#include "door.h"
#include "elevator.h"
#include <unistd.h> //sleep()


void doorOpen(elevator *heis){
    if(heis->currentFloor == heis->nextInstruction) {
        sleep(3);
    }
}


void doorOpenEmergency(elevator *heis, bool stopButton) {
    while (stopButton) {
        if(elevatorGetPosition >= 0){
        sleep(3);
        }
    }
}

void doorClose();       //Not needed if there is no actual door?