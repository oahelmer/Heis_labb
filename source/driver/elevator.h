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
} elevator;

void elevatorInit(elevator *heis);

int elevatorGetPosition(elevator *heis);