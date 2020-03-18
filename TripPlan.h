#pragma once
#include "LeakedObjectDetector.h"
#include "TopRopeRoute.h"
#include "Mountain.h"

/*
 new UDT 4:
 */

struct TripPlan
{
    TopRopeRoute routeOne;
    Mountain mountain;

    TripPlan();
    ~TripPlan();

    JUCE_LEAK_DETECTOR(TripPlan)
};
