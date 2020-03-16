#include "BoulderProblem.h"

/*
BoulderProblem::BoulderProblem() : problemGrade( 3 ), wallAngle( 30 ) {}
~BoulderProblem() 
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
*/

 
void BoulderProblem::Hold::printHoldInfo()
{
    std::cout << "Hold Type: " << this->holdType;
    std::cout << "\nHold Size: " << this->holdSize;
    std::cout << "\nHold Height: " << this->holdHeight;
    std::cout << std::endl;
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
