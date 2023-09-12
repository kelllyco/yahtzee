// this file contains the function, constructor, and variable definitions for the cup of dice class
// it can be included in other files to allow the cup of dice class to be utilized inside them

// the dicecup class has ownership over the dice objects, and it handles all interactions that manage
// multiple dice

#ifndef DICE_CUP
#define DICE_CUP

#include "Dice.h"
#include <vector>

using namespace std;

class DiceCup
{
   public:
      // inits five dice and add them to the array
      // init does not roll, have to do the first actual roll as you would in the game irl
      DiceCup();

      // this function adds the dice stored at index "int" to the vector storing the dice to be rolled
      void addToCup(int);

      // rolls each indv dice in the cup vector, also removes them from the vector, leaving w/ an empty cup
      void roll();

      // sets times rolled to zero, is called at the end of each round
      void resetTimesRolled();

      // this returns a pointer to the cup of dice vector, its used because scorecard needs to be able to refrence
      // it, as does front end stuff in game, would like to rework later to keep this pointer safer
      Dice* dangerReturnsDiceArrayPtr();


   private:
      // this is the vector that will only be updated by addToCup, and it will be wiped at the end of
      // roll, it will store the indexes of the dice to be rolled within the dice array
      // a pointer to it does get passed to scorecard and game as mentioned earlier, would like to
      // improve this system in the future
      vector <int> cupOfDice;

      // this is the array where the five dice are stored, within which the vector points
      Dice diceArray[5];

      // function to only ever be called within roll function, pops dice off the vector
      int removeFromCup();

      // track times rolled, obvi can't go over three per game rules
      int timesRolled;

      // makes the game class a friend so front end stuff can stay seperate
      friend class Game;


};

#endif