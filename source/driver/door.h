#pragma once
#include "stdbool.h"

typedef struct door
{
    bool isOpen;
} Door;


void doorOpen(elevator *Elevator);

void doorOpenEmergency(elevator *Elevator, bool stopButton);    //Kan slåes sammen med doorOpen?

void doorClose();

