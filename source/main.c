#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/elevator.h"
#include "driver/etasjeliste.h"
#include "driver/door.h"


int etasjeliste_opp[] = {0,0,0,0};
int etasjeliste_ned[] = {0,0,0,0};

int main(){
    elevio_init();
    MotorDirection direction = DIRN_STOP; // bevegelses retning
    Elevator heis;
    heis.direction = DIRN_UP; // prioritert retning

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    elevio_motorDirection(direction);
    elevatorInit(&heis);

    while(1){
        int floorState = elevio_floorSensor();

        /*
        if(heis.currentFloor == 0){
            elevio_motorDirection(DIRN_UP);
        }

        if(heis.currentFloor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }
        */

        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed){
                    etasjeliste_sett(f, b, 1);
                }
            }
        }


        // Sjekker om heisen har kolidert, setter currentFloor og etasjelys.
        if(floorState != -1){
            etasjeliste_reset(floorState);
            heis.currentFloor = floorState;
            elevio_floorIndicator(floorState);
        }

        // setter directrion og heis.direction
        direction = sjekk_om_bytte_retning(heis.currentFloor, direction, heis.direction);
        if(direction == 1){
            heis.direction = 1;
        }
        else if(direction == -1){
            heis.direction = -1;
        }

        // sjekker om heisen har kommet fram til etasjen. 
        heis.nextInstruction = etasjeliste_hent_neste(heis.currentFloor, heis.direction);
        if(heis.nextInstruction == heis.currentFloor){
            direction = DIRN_STOP;
            elevio_motorDirection(direction);
            doorOpen(&heis);
            etasjeliste_reset(heis.currentFloor);
        }
        elevio_motorDirection(direction);
        





        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);

        // printer etasjeliste for debugging
        for(int i =0; i < 4; i++){
            printf("opp: %d  ned: %d\n", etasjeliste_opp[i], etasjeliste_ned[i]);
        }
        printf("\n");
    }

    return 0;
}
