#include "elevator.h"

void elevatorInit(elevator *heis) {
    heis->currentFloor = elevatorGetPosition(heis);
    heis->door.isOpen = 0;
}

int elevatorGetPosition(elevator *heis) {
    return elevio_floorSensor();
}