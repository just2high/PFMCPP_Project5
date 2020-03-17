#pragma once
#include "LeakedObjectDetector.h"

/*
 copied UDT 3:
 */

struct Shoe
{
    float shoeSize;
    bool isMale;
    bool isBoot;
    int rubberType;
    int agressiveness;

    Shoe();
    ~Shoe();

    void shoeInfo();

    void shoeInfo_();

    bool shoeFit( float painTolerance );

    JUCE_LEAK_DETECTOR(Shoe)
};
