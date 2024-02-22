#ifndef __DOOR_H__
#define __DOOR_H__

#include "stdbool.h"
#include "elevator.h"

typedef struct
{
    bool isOpen;
} Door;

struct Elevator;


void doorOpen(struct Elevator *heis);

void doorOpenEmergency(struct Elevator *heis, bool stopButton);    //Kan slåes sammen med doorOpen?

void doorClose();

#endif