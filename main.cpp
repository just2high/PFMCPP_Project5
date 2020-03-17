/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include "LeakedObjectDetector.h"
#include <iostream>
#include <math.h>
#include "BoulderProblem.h"
#include "TopRopeRoute.h"
#include "Mountain.h"
#include "Shoe.h"
#include "TripPlan.h"
#include "Wrappers.h"

/*
 new UDT 5:
 */

struct ClimbPlan
{
    TopRopeRoute routeOne;
    Shoe shoe;

    ClimbPlan() {}
    ~ClimbPlan()
    {
        shoe.shoeInfo();
        std::cout << "Got my shoes for the climb!\n";
    }

    JUCE_LEAK_DETECTOR(ClimbPlan)
};

struct ClimbPlanWrapper
{
    ClimbPlanWrapper( ClimbPlan* ptr ) : pointerToClimbPlan( ptr ) {}
    ~ClimbPlanWrapper()
    {
        delete pointerToClimbPlan;
    }

    ClimbPlan* pointerToClimbPlan = nullptr;
};

void divider()
{
    std::cout << "\n=============================\n\n";
}

int main()
{
    TripPlanWrapper march ( new TripPlan() );

    ClimbPlanWrapper routeOne ( new ClimbPlan() );

    divider();
    
    HoldWrapper pinch ( new BoulderProblem::Hold() );

    std::cout << "Accessing member variables of pinch hold...\n";
    std::cout << "Hold Type: " << pinch.pointerToHold->holdType;
    std::cout << "\nHold Size: " << pinch.pointerToHold->holdSize;
    std::cout << "\nHold Height: " << pinch.pointerToHold->holdHeight;
    std::cout << std::endl;

    pinch.pointerToHold->printHoldInfo();

    divider();

    RouteGradeWrapper medium ( new TopRopeRoute::RouteGrade () );

    std::cout << "Grade of this medium Top Rope Route is: " << medium.pointerToRouteGrade->gradeNumber << medium.pointerToRouteGrade->gradeLetter << std::endl;

    medium.pointerToRouteGrade->printGradeInfo();

    divider();
    
    MountainWrapper jumbo ( new Mountain () );

    std::cout << "Mount Jumbo has a height of " << jumbo.pointerToMountain->height << " feet and has " << jumbo.pointerToMountain->routes << " routes\n";

    jumbo.pointerToMountain->printMountainInfo();

    divider();

    ShoeWrapper tenaya ( new Shoe () );

    std::cout << "Tenaya is a great shoe.\n";
    std::cout << "This size " << tenaya.pointerToShoe->shoeSize << ( tenaya.pointerToShoe->isBoot ? " boot" : " shoe" ) << " has type " << tenaya.pointerToShoe->rubberType << " rubber.\n";
    std::cout << "It's got an aggressiveness value of " << tenaya.pointerToShoe->agressiveness << ".\n";

    tenaya.pointerToShoe->shoeInfo();

    divider();

    std::cout << "good to go!" << std::endl;
}
