#include "BoulderProblem.h"

BoulderProblem::BoulderProblem() : problemGrade( 3 ), wallAngle( 30 ) {}
BoulderProblem::~BoulderProblem() 
{
    std::cout << "BoulderProblem dstor\n";
} 

double BoulderProblem::calculateDifficulty( double ropeLength )
{
    std::cout << "Calculating difficulty for V" << problemGrade << " problem at a " << wallAngle << " degree incline.\n";
    return ((problemGrade * crimp.holdType) / crimp.holdSize) - ropeLength;
}

void BoulderProblem::difficultyInfo()     // new function
{
    std::cout << "The grade is V" << this->problemGrade << " and the wall angle is at a " << this->wallAngle << " degree incline.\n";
}

BoulderProblem::Hold::Hold() : holdSize( 0.8 ), holdHeight( 1 ) {}
BoulderProblem::Hold::~Hold() 
{
    std::cout << "Hold dstor\n";
}

void BoulderProblem::Hold::printHoldInfo()
{
    std::cout << "Hold Type: " << holdType;
    std::cout << "\nHold Size: " << holdSize;
    std::cout << "\nHold Height: " << holdHeight;
    std::cout << std::endl;
}
