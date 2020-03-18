#include "Wrappers.h"
#include "Mountain.h"  
#include "TripPlan.h"
#include "ClimbPlan.h"


BoulderProblemWrapper::BoulderProblemWrapper( BoulderProblem* ptr ) : pointerToBoulderProblem( ptr ) {}
BoulderProblemWrapper::~BoulderProblemWrapper()
{
    delete pointerToBoulderProblem;
}


HoldWrapper::HoldWrapper( BoulderProblem::Hold* ptr ) : pointerToHold( ptr ) {}
HoldWrapper::~HoldWrapper()
{
    delete pointerToHold;
}

TopRopeRouteWrapper::TopRopeRouteWrapper( TopRopeRoute* ptr ) : pointerToTopRopeRoute( ptr ) {}
TopRopeRouteWrapper::~TopRopeRouteWrapper()
{
    delete pointerToTopRopeRoute;
}

RouteGradeWrapper::RouteGradeWrapper( TopRopeRoute::RouteGrade* ptr ) : pointerToRouteGrade( ptr ) {}
RouteGradeWrapper::~RouteGradeWrapper()
{
    delete pointerToRouteGrade;
}

MountainWrapper::MountainWrapper( Mountain* ptr ) : pointerToMountain( ptr ) {}
MountainWrapper::~MountainWrapper()
{
    delete pointerToMountain;
}

ShoeWrapper::ShoeWrapper( Shoe* ptr ) : pointerToShoe( ptr ) {}
ShoeWrapper::~ShoeWrapper()
{
    delete pointerToShoe;
}

TripPlanWrapper::TripPlanWrapper( TripPlan* ptr ) : pointerToTripPlan( ptr ) {}
TripPlanWrapper::~TripPlanWrapper()
{
    delete pointerToTripPlan;
}

ClimbPlanWrapper::ClimbPlanWrapper( ClimbPlan* ptr ) : pointerToClimbPlan( ptr ) {}
ClimbPlanWrapper::~ClimbPlanWrapper()
{
    delete pointerToClimbPlan;
}
