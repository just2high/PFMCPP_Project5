/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12 

 Create a branch named Part1

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have member functions, member variables, constructors that initialize the members. 
 Define your implementations of all functions OUTSIDE of the class. 
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 6) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 copied UDT 1:
 */


struct TopRopeRoute
{
    double wallAngle { 10 };

//  TopRopeRoute(){}

    struct RouteGrade
    {
        double gradeNumber;
        char gradeLetter; 
        
        RouteGrade() : 
        gradeNumber( 5.10 ), 
        gradeLetter( 100 ) // ascii letter 'd' 
        {}

        void printGradeInfo()
        {
            std::cout << "Grade is: " << gradeNumber << gradeLetter << std::endl;
        }
    };

    void buildRoute( int moves, double wallHeight );

    RouteGrade hard;
};

void TopRopeRoute::buildRoute( int moves, double wallHeight = 40.36 )
{
    BoulderProblem::Hold hold;

    std::cout << "The wall is at a " << wallAngle << " degree incline.\n";

    for ( int i = moves; i > 0; i-- )  // already have a for loop
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

//    Mountain(){}

    void mountainFeatures( TopRopeRoute face, BoulderProblem base, double mountain );

    void constructMountain( double baseDiameter );
};

void Mountain::mountainFeatures(TopRopeRoute face, BoulderProblem base, double mountain )
{
    std::cout << "Mountain height is " << height << " feet and has " << routes << " routes\n";

    for ( int i = this->routes; i > 0; i-- ) // already have a for loop
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

    mountainFeatures( wall, slab, mountain ); 
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

    void shoeInfo()
    {
        std::cout << "This size " << shoeSize << ( isBoot ? " boot" : " shoe" ) << " has type " << rubberType << " rubber.\n";
    }

    bool shoeFit( float painTolerance );
};

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


/*
 new UDT 5:
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
