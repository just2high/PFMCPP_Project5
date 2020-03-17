#include "BoulderProblem.h" //need to include because of nested class
#include "TopRopeRoute.h"
struct Mountain;
struct Shoe;
struct TripPlan;
struct ClimbPlan;

struct BoulderProblemWrapper
{
    BoulderProblemWrapper( BoulderProblem* ptr );
    ~BoulderProblemWrapper();

    BoulderProblem* pointerToBoulderProblem = nullptr;
};

struct HoldWrapper
{
    HoldWrapper( BoulderProblem::Hold* ptr );
    ~HoldWrapper();

    BoulderProblem::Hold* pointerToHold = nullptr;
};

struct TopRopeRouteWrapper
{
    TopRopeRouteWrapper( TopRopeRoute* ptr );
    ~TopRopeRouteWrapper();

    TopRopeRoute* pointerToTopRopeRoute = nullptr;
};

struct RouteGradeWrapper
{
    RouteGradeWrapper( TopRopeRoute::RouteGrade* ptr );
    ~RouteGradeWrapper();

    TopRopeRoute::RouteGrade* pointerToRouteGrade = nullptr;
};

struct MountainWrapper
{
    MountainWrapper( Mountain* ptr );
    ~MountainWrapper();

    Mountain* pointerToMountain = nullptr;
};

struct ShoeWrapper
{
    ShoeWrapper( Shoe* ptr );
    ~ShoeWrapper();

    Shoe* pointerToShoe = nullptr;
};

struct TripPlanWrapper
{
    TripPlanWrapper( TripPlan* ptr );
    ~TripPlanWrapper();

    TripPlan* pointerToTripPlan = nullptr;
};

struct ClimbPlanWrapper
{
    ClimbPlanWrapper( ClimbPlan* ptr );
    ~ClimbPlanWrapper();

    ClimbPlan* pointerToClimbPlan = nullptr;
};
