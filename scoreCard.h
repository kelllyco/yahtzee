// this file should contain the info for the scoring class, which should be invoked in a program as many times as there are players in a game
// it will cover all of the backend of the scorecard, none of the ui, will use a friend class for that in the temporary, eventually to
// transfer to the final gui

#ifndef SCORECARD
#define SCORECARD
#include <vector>
#include <memory>

#include "Dice.h"
#include "score.h"


class ScoreCard
{
   private:
      const int BONUS = 35;

      int upperTotal;
      int lowerTotal;

      int combinedTotal;

      string currentCategory;

      // vector of the different child classes of score, honestly inspired by chat gpt we didnt go into polymorphism deep enough for this in class
      vector <Score*> categories;

   public:
      // constructor, takes in array of dice since scorecard has ownership of the score categories and they require that array of dice
      ScoreCard(Dice*);

      // destructor, needed for dynamically allocated mem found in constructor
      ~ScoreCard();

      // basic addition functions, didnt add setters bc automated
      int getUpperTotal();
      int getUpperWithBonus();
      int getLowerTotal();
      int getCombinedTotal();

      // not a permanent thing, but a way for me to see what's going on
      void OUTPUTCATEGORIES() const;

      // this takes in the user's desired category
      // if the category exist and doesn't already have an assigned score, returns true
      // otherwise, it returns false
      bool attemptSetScore(const string&);

};

#endif