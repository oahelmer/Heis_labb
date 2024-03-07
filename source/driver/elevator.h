#ifndef __ELEVATOR_H__
#define __ELEVATOR_H__



#include "elevio.h"


typedef enum
{
    FIRST_FLOOR     = 0,
    SECOND_FLOOR    = 1,
    THIRD_FLOOR     = 2,
    FOURTH_FLOOR    = 3
} Floor;

typedef struct {
    Floor currentFloor;
    int nextInstruction;
    int direction;
} Elevator;

void elevatorInit(Elevator *heis);

int elevatorGetPosition(Elevator *heis);

#endif