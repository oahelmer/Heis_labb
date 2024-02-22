#include "elevator.h"

void elevatorInit(elevator *Elevator, floor position) {
    Elevator->currentPosition = position;
}

int elevatorGetPosition(elevator *heis) {
    return elevio_floorSensor();
}