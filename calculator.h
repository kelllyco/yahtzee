#ifndef CALCULATOR
#define CALCULATOR

#include "Dice.h"
#include <iostream>

using namespace std;

// this is the calculator class
// its current usage and what i believe it will end up being used as are very different
// and im pretty sure im gonna update this next, so i wont describe it too much

// basically, rn it can take in a array of Dice and calculate the value that the array would
// yield for each category
class Calculator
{
   private:
      // fills an array that has the number of times that each roll shows up, returns nothing
      void fillCounter();

      // the array that is filled by fillCounter method
      int counter[6] = {0, 0, 0, 0, 0, 0};

      // minor helper functions
      // takes in the number that is being searched for, returns number of occurences in array
      int helperSum(int);

      // adds the sum of the dice in the array
      int addAll();

      // private member var to hold passed in array of dice
      Dice* arrayOfDice;

      // clears the array that counts how many occurences of a certain dice in an array
      void clearCounter();

   public:
      // constructor that takes in a pointer to an array of dice objects
      Calculator(Dice*);

      // calculator functions that use the dice array to calculate the score the array would yield for each category
      int calcAces();
      int calcTwos();
      int calcThrees();
      int calcFours();
      int calcFives();
      int calcSixes();

      int calcThreeOfAKind();
      int calcFourOfAKind();
      int calcFullHouse();
      int calcSmStraight();
      int calcLgStraight();
      int calcYahtzee();
      int calcChance();

};

#endif