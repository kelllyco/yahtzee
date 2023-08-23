// Game will hold only really basic command line ui stuff, will eventually be taken over by a real gui,
// but i need to do the logic of everything first

// this is why most of the functions in game are pretty stupid, just calling other functions and interacting
// with the user

#ifndef GAME
#define GAME

#include "diceCup.h"

class Game {
   private:
      // holder for dicecup pointer
      DiceCup *currentCup = nullptr;

   public:
      // welcomes user
      void welcomeMessage();

      // asks user if wants to roll again
      bool rollAgain();

      // prompts the user to select which category they want their roll to count for
      // returns a number which corresponds to the category in scorecard
      int selectCategory();

      // rolls the dice in the cup, outputs what's going on
      void rollAndOutput();

      // prompts the user to enter dice, giving instructions and has error checking built in
      void userSelection();

      // constructor for game, has to take in a pointer to the current set of dice being worked with
      Game(DiceCup *);
      
};

#endif