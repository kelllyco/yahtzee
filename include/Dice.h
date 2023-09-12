// this file contains the function, constructor, and variable definitions for the dice class
// it can be included in other files to allow the dice class to be utilized inside of them

// the point of this class is to represent individual dice, its very simple, it just rolls dice and returns their values

#ifndef DICE_H
#define DICE_H

#include <ctime>
#include <cstdlib>

using namespace std;

class Dice
{
   public:
      // Dice constructor
      Dice();

      // Works functionally as set current value
      void rollDice();

      // Getter for current value
      int getCurrentValue();

   private:
      // stores dice's current value
      int currentValue;

};

#endif