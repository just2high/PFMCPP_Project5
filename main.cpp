/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some. 
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

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
    };

    double calculateDifficulty( double ropeLength );

    Hold crimp;
};

void BoulderProblem::Hold::printHoldInfo()
{
    std::cout << "Hold Type: " << holdType;
    std::cout << "\nHold Size: " << holdSize;
    std::cout << "\nHold Height: " << holdHeight;
    std::cout << std::endl;
}

double BoulderProblem::calculateDifficulty( double ropeLength )
{
    std::cout << "Calculating difficulty for V" << problemGrade << " problem at a " << wallAngle << " degree incline.\n";
    return ((problemGrade * crimp.holdType) / crimp.holdSize) - ropeLength;
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
    };

    void buildRoute( int moves, double wallHeight );

    RouteGrade hard;
};

void TopRopeRoute::RouteGrade::printGradeInfo()
{
    std::cout << "Grade is: " << gradeNumber << gradeLetter << std::endl;
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

    bool shoeFit( float painTolerance );
};

void Shoe::shoeInfo()
{
    std::cout << "This size " << shoeSize << ( isBoot ? " boot" : " shoe" ) << " has type " << rubberType << " rubber.\n";
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

int main()
{
    TripPlan march;

    ClimbPlan routeOne;

    std::cout << "good to go!" << std::endl;
}
