#pragma once
#include "LeakedObjectDetector.h"

struct BoulderProblem
{
    int problemGrade;
    double wallAngle;
    
    BoulderProblem();
    ~BoulderProblem();
    
    struct Hold
    {
        int holdType { 2 };
        double holdSize; 
        double holdHeight;

        Hold();
        ~Hold();

        void printHoldInfo();

        JUCE_LEAK_DETECTOR(Hold)
    };

    double calculateDifficulty( double ropeLength );
    void difficultyInfo();

    Hold crimp;
    
    JUCE_LEAK_DETECTOR( BoulderProblem )
};
