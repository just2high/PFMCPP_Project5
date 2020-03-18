#include "Shoe.h"

Shoe::Shoe() : shoeSize( 8.5f ), isMale ( true ), isBoot ( false ), rubberType ( 3 ), agressiveness ( 1 ) {}

Shoe::~Shoe()
{
    std::cout << "Shoe dstor\n";
}

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
