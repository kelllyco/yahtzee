// this file contains the function, constructor, and variable definitions for the cup of dice class
// it can be included in other files to allow the cup of dice class to be utilized inside them

#ifndef DICE_CUP
#define DICE_CUP

// should probably make a different program here, a yahtzee cheater program, that takes given die and sums stuff up, bc that function will be used lots and is very important
// want to figure out a fun ui for this too, do research once you have wifi
// honestly will want to run this each time for when its the computer's turn

// imports the user defined header files
#include "Dice.h"

#include <vector>

using namespace std;

class DiceCup
{
   public:
      // default constructor
      DiceCup();

      void addToCup(int);
      void roll();

      Dice* dangerReturnsDiceArrayPtr();


   private:
      // this is the vector that will only be updated by addToCup, and it will be wiped at the end of
      // roll, it will store the indexes of the dice to be rolled within the dice array
      vector <int> diceIndexesVector;

      // so this is the array where the five dice are stored, within which the vector will point
      Dice diceArray[5];

      // function to only ever really be called within roll function
      int removeFromCup();

      // track times rolled, obvi can't go over three
      int timesRolled;

      friend class Game;


};

#endif