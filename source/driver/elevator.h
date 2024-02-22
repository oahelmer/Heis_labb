#pragma once
#include "elevio.h"
#include "door.h"

typedef enum
{
    FIRST_FLOOR     = 0,
    SECOND_FLOOR    = 1,
    THIRD_FLOOR     = 2,
    FOURTH_FLOOR    = 3
} Floor;

typedef struct
{
    Floor currentFloor;
    int nextInstruction;
    Door door;
} Elevator;

void elevatorInit(Elevator *heis);

int elevatorGetPosition(Elevator *heis);