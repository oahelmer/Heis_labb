#include "elevator.h"

void elevatorInit(Elevator *heis) {
    heis->currentFloor = elevatorGetPosition(heis);
    heis->door_Open = 0;
}

int elevatorGetPosition(Elevator *heis) {
    return elevio_floorSensor();
}