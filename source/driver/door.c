#include "door.h"
#include "elevator.h"
#include <unistd.h> //sleep()

void doorOpen(elevator *Elevator){
    if(Elevator->currentPosition == Elevator->nextInstruction) {
        sleep(3);
    }
}


void doorOpenEmergency(elevator *Elevator, bool stopButton) {
    while (stopButton) {
        if(elevatorGetPosition >= 0){
        sleep(3);
        }
    }
}

void doorClose();       //Not needed if there is no actual door?