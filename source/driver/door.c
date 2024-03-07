#include "door.h"
#include <unistd.h> //sleep()


void doorOpen(Elevator *heis){
    if(heis->currentFloor == heis->nextInstruction) {  
        elevio_doorOpenLamp(1);
        while(elevio_obstruction()){
            nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
        }
        sleep(3);
        elevio_doorOpenLamp(0);

    }
}


void doorOpenEmergency(Elevator *heis, bool stopButton) {
    while (stopButton) {
        if(elevatorGetPosition >= 0){
        sleep(3);
        }
    }
}

void doorClose();       //Not needed if there is no actual door?