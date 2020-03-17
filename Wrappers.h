struct BoulderProblemWrapper
{
    BoulderProblemWrapper( BoulderProblem* ptr ) : pointerToBoulderProblem( ptr ) {}
    ~BoulderProblemWrapper()
    {
        delete pointerToBoulderProblem;
    }

    BoulderProblem* pointerToBoulderProblem = nullptr;
};

struct HoldWrapper     // Did I declare this wrong?
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
