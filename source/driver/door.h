#pragma once
#include "stdbool.h"
#include "elevator.h"

typedef struct door
{
    bool isOpen;
} Door;


void doorOpen(Elevator *heis);

void doorOpenEmergency(Elevator *heis, bool stopButton);    //Kan slåes sammen med doorOpen?

void doorClose();

