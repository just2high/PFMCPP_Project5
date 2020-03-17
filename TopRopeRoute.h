#pragma once
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct TopRopeRoute
{
    double wallAngle { 10 };

    TopRopeRoute();
    ~TopRopeRoute();

    struct RouteGrade
    {
        double gradeNumber;
        char gradeLetter; 
        
        RouteGrade();
        ~RouteGrade();

        void printGradeInfo();

        JUCE_LEAK_DETECTOR(RouteGrade)
    };

    void buildRoute( int moves, double wallHeight );

    RouteGrade hard;

    JUCE_LEAK_DETECTOR(TopRopeRoute)
};

