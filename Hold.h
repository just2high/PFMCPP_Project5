#pragma once
#include "LeakedObjectDetector.h"

struct Hold
{
    int holdType { 2 };
    double holdSize; 
    double holdHeight;

    void printHoldInfo();

    JUCE_LEAK_DETECTOR(Hold)
};
