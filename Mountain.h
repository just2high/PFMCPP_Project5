#pragma once
#include "LeakedObjectDetector.h"
#include "BoulderProblem.h"
#include "TopRopeRoute.h"

/*
 copied UDT 2:
 */

struct Mountain 
{
    int height { 15 };
    int routes { 20 };

    Mountain();
    ~Mountain();

    void printMountainInfo();

    void mountainFeatures( TopRopeRoute face, BoulderProblem base, double mountain );

    void constructMountain( double baseDiameter );

    JUCE_LEAK_DETECTOR(Mountain)
};


