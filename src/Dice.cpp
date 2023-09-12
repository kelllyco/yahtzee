// this file contains the funciton, constructor, and static variable bodies required for the dice class
// it includes the Dice.h file, which has the definitions for these class members

// imports user defined header file
#include "../include/Dice.h"

using namespace std;

// Dice constructor, takes in an int which is set to the objects value
Dice::Dice()
{
   rollDice();
}

// 'Rolls' the dice, is seeded by housekeeping
void Dice::rollDice()
{
   currentValue = (rand() % 6) + 1;
}

// returns the dice's current value as an int
int Dice::getCurrentValue()
{
   return currentValue;
}
