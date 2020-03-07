/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */











#include <math.h>
//Required UDT for Copied UDT 1 to work

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

        void printHoldInfo_();     // new function
    };

    double calculateDifficulty( double ropeLength );
    void difficultyInfo();

    Hold crimp;
};

void BoulderProblem::Hold::printHoldInfo()
{
    std::cout << "Hold Type: " << this->holdType;
    std::cout << "\nHold Size: " << this->holdSize;
    std::cout << "\nHold Height: " << this->holdHeight;
    std::cout << std::endl;
}

double BoulderProblem::calculateDifficulty( double ropeLength )
{
    std::cout << "Calculating difficulty for V" << problemGrade << " problem at a " << wallAngle << " degree incline.\n";
    return ((problemGrade * crimp.holdType) / crimp.holdSize) - ropeLength;
}

void BoulderProblem::difficultyInfo()     // new function
{
    std::cout << "The grade is V" << this->problemGrade << " and the wall angle is at a " << this->wallAngle << " degree incline.\n";
}

/*
 copied UDT 1:
 */

struct TopRopeRoute
{
    double wallAngle { 10 };

    TopRopeRoute(){}
    ~TopRopeRoute()
    {
        std::cout << "TopRopeRoute dstor\n";
    }

    struct RouteGrade
    {
        double gradeNumber;
        char gradeLetter; 
        
        RouteGrade() : 
        gradeNumber( 5.10 ), 
        gradeLetter( 'd' )
        {}

        ~RouteGrade()
        {
            std::cout << "RouteGrade dstor\n";
        }

        void printGradeInfo();
        void printGradeInfo_();     // new function
    };

    void buildRoute( int moves, double wallHeight );

    RouteGrade hard;
};

void TopRopeRoute::RouteGrade::printGradeInfo()
{
    std::cout << "Grade is: " << this->gradeNumber << this->gradeLetter << std::endl;
}

void TopRopeRoute::buildRoute( int moves, double wallHeight = 40.36 )
{
    BoulderProblem::Hold hold;

    std::cout << "The wall is at a " << wallAngle << " degree incline.\n";

    for ( int i = moves; i > 0; --i )  // already have a for loop
    {
         hold.holdHeight = ( wallHeight / moves ) * i;
         std::cout << "Hold height for move " << i << " is: " << hold.holdHeight << std::endl;
    }
}

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
};

void divider()
{
    std::cout << "\n=============================\n\n";
}

int main()
{
    TripPlan march;

    ClimbPlan routeOne;

    divider();

    BoulderProblem::Hold pinch;
    
    std::cout << "Accessing member variables of pinch hold...\n";
    std::cout << "Hold Type: " << pinch.holdType;
    std::cout << "\nHold Size: " << pinch.holdSize;
    std::cout << "\nHold Height: " << pinch.holdHeight;
    std::cout << std::endl;

    pinch.printHoldInfo();

    divider();

    TopRopeRoute::RouteGrade medium;

    std::cout << "Grade of this medium Top Rope Route is: " << medium.gradeNumber << medium.gradeLetter << std::endl;

    medium.printGradeInfo();

    divider();

    Mountain Jumbo;
    
    std::cout << "Mount Jumbo has a height of " << Jumbo.height << " feet and has " << Jumbo.routes << " routes\n";

    Jumbo.printMountainInfo();

    divider();

    Shoe tenaya;

    std::cout << "Tenaya is a great shoe.\n";
    std::cout << "This size " << tenaya.shoeSize << ( tenaya.isBoot ? " boot" : " shoe" ) << " has type " << tenaya.rubberType << " rubber.\n";
    std::cout << "It's got an aggressiveness value of " << tenaya.agressiveness << ".\n";

    tenaya.shoeInfo();

    divider();

    std::cout << "good to go!" << std::endl;
}
