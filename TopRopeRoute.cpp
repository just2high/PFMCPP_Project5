#include "TopRopeRoute.h"

TopRopeRoute::TopRopeRoute(){}
TopRopeRoute::~TopRopeRoute()
{
    std::cout << "TopRopeRoute dstor\n";
}

TopRopeRoute::RouteGrade::RouteGrade() : 
gradeNumber( 5.10 ), 
gradeLetter( 'd' )
{}

TopRopeRoute::RouteGrade::~RouteGrade()
{
    std::cout << "RouteGrade dstor\n";
}

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
