#include "TripPlan.h"

TripPlan::TripPlan() {}
TripPlan::~TripPlan()
{
    std::cout << "Trip planned!\n";
    mountain.constructMountain( 34.27 );
}
