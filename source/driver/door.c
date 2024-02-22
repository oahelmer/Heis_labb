#include "door.h"
#include "elevator.h"
#include <unistd.h> //sleep()


void doorOpen(Elevator *heis){
    if(heis->currentFloor == heis->nextInstruction) {
        sleep(3);
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