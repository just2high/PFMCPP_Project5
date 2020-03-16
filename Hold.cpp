#include "Hold.h"

Hold::Hold() : holdSize( 0.8 ), holdHeight( 1 ) {}
Hold::~Hold() 
{
    std::cout << "Hold dstor\n";
}

void printHoldInfo()
{
    std::cout << "Hold Type: " << this->holdType;
    std::cout << "\nHold Size: " << this->holdSize;
    std::cout << "\nHold Height: " << this->holdHeight;
    std::cout << std::endl;
}