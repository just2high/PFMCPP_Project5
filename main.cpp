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
#include "TopRoupeRoute.h"
#include "Wrappers.h"

/*
 copied UDT 2:
 */

struct Mountain 
{
    int height { 15 };
    int routes { 20 };

    Mountain(){}
    ~Mountain()
    {
        std::cout << "Mountain dstor\n";
    }

    void printMountainInfo();     // new function

    void mountainFeatures( TopRopeRoute face, BoulderProblem base, double mountain );

    void constructMountain( double baseDiameter );

    JUCE_LEAK_DETECTOR(Mountain)
};

void Mountain::mountainFeatures(TopRopeRoute face, BoulderProblem base, double mountain )
{
    std::cout << "Mountain height is " << height << " feet and has " << routes << " routes\n";

    for ( int i = this->routes; i > 0; --i ) // already have a for loop
    {
        std::cout << "Route #" << i << std::endl;
        
        face.buildRoute( this->height, ( mountain + base.calculateDifficulty( 20.25 ) ) );
    }
}

void Mountain::printMountainInfo()  // new function
{
    std::cout << "Mountain height is " << this->height << " feet and has " << this->routes << " routes\n";
}

void Mountain::constructMountain( double baseDiameter )
{
    TopRopeRoute wall;
    BoulderProblem slab;

    double mountain = M_PI* pow( baseDiameter / 2, 2 ) * this->height;

    std::cout << "The mountain takes up " << mountain << " ft^3 of space.\n";

//    mountainFeatures( wall, slab, mountain ); 
}

struct MountainWrapper
{
    MountainWrapper( Mountain* ptr ) : pointerToMountain( ptr ) {}
    ~MountainWrapper()
    {
        delete pointerToMountain;
    }

    Mountain* pointerToMountain = nullptr;
};

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

    Shoe() : shoeSize( 8.5f ), isMale ( true ), isBoot ( false ), rubberType ( 3 ), agressiveness ( 1 ) {}

    ~Shoe()
    {
        std::cout << "Shoe dstor\n";
    }

    void shoeInfo();

    void shoeInfo_();   // new function

    bool shoeFit( float painTolerance );

    JUCE_LEAK_DETECTOR(Shoe)
};

void Shoe::shoeInfo()
{        
     std::cout << "This size " << this->shoeSize << ( isBoot ? " boot" : " shoe" ) << " has type " << this->rubberType << " rubber.\n";
        std::cout << "The aggressiveness is " << this->agressiveness << std::endl;
}

bool Shoe::shoeFit( float painTolerance ) // modified to become while loop
{    
    while ( painTolerance <= shoeSize )
    {
        std::cout << "The size " << shoeSize << " shoe doesn't fit!\n";

        shoeSize = shoeSize - 0.5f;
    }

    std::cout << "The size " << shoeSize << " shoe fits!\n";

    return true;
}

struct ShoeWrapper
{
    ShoeWrapper( Shoe* ptr ) : pointerToShoe( ptr ) {}
    ~ShoeWrapper()
    {
        delete pointerToShoe;
    }

    Shoe* pointerToShoe = nullptr;
};

/*
 new UDT 4:
 */

struct TripPlan
{
    TopRopeRoute routeOne;
    Mountain mountain;

    TripPlan() {}
    ~TripPlan()
    {
        std::cout << "Trip planned!\n";
        mountain.constructMountain( 34.27 );
    }

    JUCE_LEAK_DETECTOR(TripPlan)
};

struct TripPlanWrapper
{
    TripPlanWrapper( TripPlan* ptr ) : pointerToTripPlan( ptr ) {}
    ~TripPlanWrapper()
    {
        delete pointerToTripPlan;
    }

    TripPlan* pointerToTripPlan = nullptr;
};

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
