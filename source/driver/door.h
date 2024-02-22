#ifndef __DOOR_H__
#define __DOOR_H__

#include "stdbool.h"
#include "elevator.h"

typedef struct Door
{
    bool isOpen;
} Door;


void doorOpen(Elevator *heis);

void doorOpenEmergency(Elevator *heis, bool stopButton);    //Kan slåes sammen med doorOpen?

void doorClose();

#endif