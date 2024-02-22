#pragma once
#include "stdbool.h"

typedef struct door
{
    bool isOpen;
} Door;


void doorOpen(Elevator *Elevator);

void doorOpenEmergency(Elevator *Elevator, bool stopButton);    //Kan slåes sammen med doorOpen?

void doorClose();

