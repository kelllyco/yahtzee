// this file should contain the info for the scoring class, which should be invoked in a program as many times as there are players in a game
// it will cover all of the backend of the scorecard, none of the ui, will use a friend class for that in the temporary, eventually to
// transfer to the final gui

#ifndef SCORECARD
#define SCORECARD

#include "score.h"

class ScoreCard
{
   private:
      Score aces;
      Score twos;
      Score threes;
      Score fours;
      Score fives;
      Score sixes;

      Score threeOfAKind;
      Score fourOfAKind;
      Score fullHouse;
      Score smStraight;
      Score lgStraight;
      Score yahtzee;
      Score chance;

      static int bonus;

      int upperTotal;
      int lowerTotal;

      int combinedTotal;

      // returns the score that the passed integer corresponds to
      Score getScoreObj(int);

   public:
      // sets the scores value, returns 0 if fails, 1 if succeeds
      bool setScoreVal(int);
      int getUpperTotal();
      int getUpperWithBonus();
      int getLowerTotal();
      int getCombinedTotal();

};

#endif