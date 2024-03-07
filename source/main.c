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
int lysliste_opp[] = {0,0,0,0};
int lysliste_ned[] = {0,0,0,0};
int lysliste_inne[] = {0,0,0,0};
bool lysFlagg = 0;

void setButtonLight();
void resetButtonLight(int currentFloor);

int main(){
    elevio_init();
    MotorDirection direction = DIRN_STOP; // bevegelses retning
    Elevator heis;
    heis.direction = DIRN_UP; // prioritert retning
    int forrigeEtasje = 0;

    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

//    elevio_motorDirection(direction);
/*     elevatorInit(&heis);
 */
    //Startup the elevator goes down until floorstate is defined
    while(elevio_floorSensor() == -1){
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
        elevio_motorDirection(DIRN_DOWN);
    }elevio_motorDirection(DIRN_STOP);


    while(1){
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
                if(btnPressed) {
                    switch (b)
                    {
                    case BUTTON_HALL_UP:
                        lysliste_opp[f] = 1;
                        break;
                    case BUTTON_HALL_DOWN:
                        lysliste_ned[f] = 1;
                        break;
                    case BUTTON_CAB:
                        lysliste_inne[f] = 1;
                        break;
                    default:
                        break;
                    }
                }
                //elevio_buttonLamp(f, b, btnPressed);
                if(btnPressed){
                    etasjeliste_sett(f, b, 1);
                }
            }
        }

        setButtonLight();
        int floorState = elevio_floorSensor();

        // Sjekker om heisen ikke er i etasje setter currentFloor og etasjelys.
        if(floorState != -1){
            heis.currentFloor = floorState;
            elevio_floorIndicator(floorState);
            direction = 0;
            elevio_motorDirection(direction);
            forrigeEtasje = floorState;
        
        
            // setter direction og heis.direction
            direction = sjekk_om_bytte_retning(heis.currentFloor, direction, heis.direction);
            if(direction == 1){
                heis.direction = 1;
            }
            else if(direction == -1){
                heis.direction = -1;
            }

            //  sjekker om heisen har kommet fram til etasjen.
            heis.nextInstruction = etasjeliste_hent_neste(heis.currentFloor, heis.direction);
            if(heis.nextInstruction == heis.currentFloor){
                direction = DIRN_STOP;
                elevio_motorDirection(direction);
                doorOpen(&heis);
                etasjeliste_reset(heis.currentFloor);
                resetButtonLight(heis.currentFloor);            
            }
        }
        elevio_motorDirection(direction);

        if(floorState != -1 && !lysFlagg){
            elevio_floorIndicator(floorState);
            lysFlagg = 1;
        }
        else if(!lysFlagg){
            elevio_floorIndicator(forrigeEtasje);
        } else if(floorState == -1 && lysFlagg){
            lysFlagg = 0;
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
        // nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);

        // printer etasjeliste for debugging
        printf("floorState: %d\n", floorState);
        for(int i =0; i < 4; i++){
            printf("opp: %d  ned: %d  lys_opp: %d  lys_ned: %d  lys_inne %d\n", etasjeliste_opp[i], etasjeliste_ned[i], lysliste_opp[i], lysliste_ned[i], lysliste_inne[i]);
        
        }
        printf("\n");

        
    }

    return 0;
}

void setButtonLight() {
    for(int i =0; i < 4; i++){
        if(lysliste_opp[i] == 1){
            elevio_buttonLamp(i, BUTTON_HALL_UP, 1);
        }
        if(lysliste_ned[i] == 1){
            elevio_buttonLamp(i, BUTTON_HALL_DOWN, 1);
        }
        if(lysliste_inne[i] == 1){
            elevio_buttonLamp(i, BUTTON_CAB, 1);
        }            
    }
}

void resetButtonLight(int currentFloor) {
    if(lysliste_opp[currentFloor] == 1){
    elevio_buttonLamp(currentFloor, BUTTON_HALL_UP, 0);
    lysliste_opp[currentFloor] = 0;
    }
    if(lysliste_ned[currentFloor] == 1){
        elevio_buttonLamp(currentFloor, BUTTON_HALL_DOWN, 0);
        lysliste_ned[currentFloor] = 0;
    }
    if(lysliste_inne[currentFloor] == 1){
        elevio_buttonLamp(currentFloor, BUTTON_CAB, 0);
        lysliste_inne[currentFloor] = 0;
    }  
}