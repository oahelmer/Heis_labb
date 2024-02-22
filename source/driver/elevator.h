#pragma once
#include "elevio.h"

typedef enum
{
    FIRST_FLOOR     = 0,
    SECOND_FLOOR    = 1,
    THIRD_FLOOR     = 2,
    FOURTH_FLOOR    = 3
} floor;

typedef struct
{
    floor currentPosition;
    int nextInstruction;

} elevator;


void elevatorInit(elevator *heis, floor position);
int elevatorGetPosition(elevator *heis);