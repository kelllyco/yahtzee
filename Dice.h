// this file contains the function, constructor, and variable definitions for the card class
// it can be included in other files to allow the dice class to be utilized inside of them

#ifndef DICE_H
#define DICE_H

#include <string>

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

      // to string definition, returns current value as a string
      string stringCurrentValue();

   private:
      // static array definitions

      // is this really the most efficient way to do this? like i know its only 
      // six ints so it doesnt really matter, but wouldnt each init of a dice create a new
      // array, even though they're all going to say the same thing?

      // i guess thats why you use destructors lol
      static string diceStrings[6];

      int currentValue;

};

#endif