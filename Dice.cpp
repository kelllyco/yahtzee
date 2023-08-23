// this file contains the funciton, constructor, and static variable bodies required for the Card class
// it includes the Dice.h file, which has the definitions for these class members
// it is compiled into a .o file, which allows it to be compiled in the main driver function of the program, allowing the program to use these class members

// imports user defined header file
#include "Dice.h"
//#include "housekeeping.h"

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Dice constructor, takes in an int which is set to the objects value
Dice::Dice()
{
   rollDice();
}

// 'Rolls' the dice
void Dice::rollDice()
{
   currentValue = (rand() % 6) + 1;
}

// returns the dice's current value as an int
int Dice::getCurrentValue()
{
   return currentValue;
}

// function to return what the value rolled on the dice is as a string
string Dice::stringCurrentValue()
{
   // init needed variable, set it to associated string in diceStrings array
   string numberValue = diceStrings[currentValue - 1];

   return numberValue;
}

// sets values for static array classes
string Dice::diceStrings[6] = {"One", "Two", "Three", "Four", "Five", "Six"};