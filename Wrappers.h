
struct BoulderProblemWrapper
{
    BoulderProblemWrapper( BoulderProblem* ptr ) : pointerToBoulderProblem( ptr ) {}
    ~BoulderProblemWrapper()
    {
        delete pointerToBoulderProblem;
    }

    BoulderProblem* pointerToBoulderProblem = nullptr;
};

struct HoldWrapper
{
    HoldWrapper( BoulderProblem::Hold* ptr ) : pointerToHold( ptr ) {}
    ~HoldWrapper()
    {
        delete pointerToHold;
    }

    BoulderProblem::Hold* pointerToHold = nullptr;
};

struct TopRopeRouteWrapper
{
    TopRopeRouteWrapper( TopRopeRoute* ptr ) : pointerToTopRopeRoute( ptr ) {}
    ~TopRopeRouteWrapper()
    {
        delete pointerToTopRopeRoute;
    }

    TopRopeRoute* pointerToTopRopeRoute = nullptr;
};

struct RouteGradeWrapper
{
    RouteGradeWrapper( TopRopeRoute::RouteGrade* ptr ) : pointerToRouteGrade( ptr ) {}
    ~RouteGradeWrapper()
    {
        delete pointerToRouteGrade;
    }

    TopRopeRoute::RouteGrade* pointerToRouteGrade = nullptr;
};

struct MountainWrapper
{
    MountainWrapper( Mountain* ptr ) : pointerToMountain( ptr ) {}
    ~MountainWrapper()
    {
        delete pointerToMountain;
    }

    Mountain* pointerToMountain = nullptr;
};

struct ShoeWrapper
{
    ShoeWrapper( Shoe* ptr ) : pointerToShoe( ptr ) {}
    ~ShoeWrapper()
    {
        delete pointerToShoe;
    }

    Shoe* pointerToShoe = nullptr;
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
