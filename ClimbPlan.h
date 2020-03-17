#pragma once
#include "LeakedObjectDetector.h"
#include "TopRopeRoute.h"
#include "Shoe.h"

/*
 new UDT 5:
 */

struct ClimbPlan
{
    TopRopeRoute routeOne;
    Shoe shoe;

    ClimbPlan();
    ~ClimbPlan();

    JUCE_LEAK_DETECTOR(ClimbPlan)
};
