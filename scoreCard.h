// this file should contain the info for the scoring class, which should be invoked in a program as many times as there are players in a game
// it will cover all of the backend of the scorecard, none of the ui, will use a friend class for that in the temporary, eventually to
// transfer to the final gui

#ifndef SCORECARD
#define SCORECARD

#include "Dice.h"
#include "score.h"

class ScoreCard
{
   private:
      const int BONUS = 35;

      int upperTotal;
      int lowerTotal;

      // this will not work, but im glad that I realized it now, i need to get rid of my constructors for the score categories,
      // instead i should give each category that has a function to set the dice array pointer situation up
      // scoreCards constructor will call this function for each category so its done automatically

      int combinedTotal;

      // returns the score that the passed integer corresponds to
      Score getScoreObj(int);

   public:
      // constructor, takes in array of dice since scorecard has ownership of the score categories and they require that array of dice
      ScoreCard(Dice*);

      // sets the scores value, returns 0 if fails, 1 if succeeds
      bool setScoreVal(int);

      // basic addition functions, didnt add setters bc automated
      int getUpperTotal();
      int getUpperWithBonus();
      int getLowerTotal();
      int getCombinedTotal();

};

#endif