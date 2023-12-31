// Game will hold only really basic command line ui stuff, will eventually be taken over by a real gui,
// but i need to do the logic of everything first
// this is why most of the functions in game are pretty lame, just calling other functions and interacting
// with the user, all this stuff should be able to be taken over by js really easily

// THIS IS BUILT FOR MAC/LINUX, DOES NOT CURRENTLY SUPPORT WINDOWS

#ifndef GAME
#define GAME

#include "diceCup.h"
#include "scoreCard.h"
#include <cstdlib>
#include <cctype>
#include <unistd.h>
#include <iostream>
#include <ctype.h>

class Game {
   private:
      // holder for dicecup pointer
      DiceCup *currentCup;

   public:
      // welcomes user, gives basic instruction
      void welcomeMessage(const ScoreCard*);

      // gets desired dice from user, returns false if user entered nothing
      bool selectDice();

      // rolls the dice in the cup, outputs what's going on
      void rollAndOutput();

      // asks user where to add score
      void whichCategory(ScoreCard*);

      // outputs the current scorecard and resets stuff to play the next round
      void nextTurn(const ScoreCard*);

      // constructor for game, has to take in a pointer to the current set of dice being worked with
      Game(DiceCup *);

      // calls final calculations and outputs to user
      void endOfGame(ScoreCard*);
      
};

#endif