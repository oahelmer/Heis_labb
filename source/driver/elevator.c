#include "elevator.h"

void elevatorInit(Elevator *heis) {
    while (elevatorGetPosition(heis) == -1)
    {
        elevio_motorDirection(DIRN_DOWN);
    }
    heis->currentFloor = elevatorGetPosition(heis);
    heis->door_Open = 0;
}

int elevatorGetPosition(Elevator *heis) {
    return elevio_floorSensor();
}