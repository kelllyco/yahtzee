// this file should contain the info for the scoring class, which should be invoked in a program as many times as there are players in a game
// it will cover all of the backend of the scorecard, none of the ui, will use Game for that for the meantime
// has ownership over score and all its children

#ifndef SCORECARD
#define SCORECARD

#include <vector>
#include <memory>
#include <iostream>
#include "Dice.h"
#include "score.h"


class ScoreCard
{
   private:
      // holds vital scoring info
      int upperTotal;
      int lowerTotal;

      // holds final score of game
      int combinedTotal;

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
      // honestly its become semi permanent...it doesnt feel like its worth my time to properly implement Game as
      // a friend class since my next step with this project will be to eradicate game and make a
      // proper ui that doesnt give me a headache to stare at
      void OUTPUTCATEGORIES() const;

      // this takes in the user's desired category
      // if the category exists and doesn't already have an assigned score, returns true
      // otherwise, it returns false
      bool attemptSetScore(const string&);

};

#endif