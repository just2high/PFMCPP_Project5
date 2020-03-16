#pragma once
#include "LeakedObjectDetector.h"
// #include "Hold.cpp"

/*
struct BoulderProblem
{
    int problemGrade;
    double wallAngle;
    
    struct Hold;

    double calculateDifficulty( double ropeLength );
    void difficultyInfo();

    Hold crimp;
    
    JUCE_LEAK_DETECTOR( BoulderProblem )
};
*/

struct BoulderProblem
{
    int problemGrade;
    double wallAngle;
    
    BoulderProblem() : problemGrade( 3 ), wallAngle( 30 ) {}
    ~BoulderProblem() 
    {
        std::cout << "BoulderProblem dstor\n";
    }

    struct Hold
    {
        int holdType { 2 };
        double holdSize; 
        double holdHeight;

        Hold() : holdSize( 0.8 ), holdHeight( 1 ) {}
        ~Hold() 
        {
            std::cout << "Hold dstor\n";
        }

        void printHoldInfo();

        JUCE_LEAK_DETECTOR(Hold)
    };

    double calculateDifficulty( double ropeLength );
    void difficultyInfo();

    Hold crimp;
    
    JUCE_LEAK_DETECTOR( BoulderProblem )
};
