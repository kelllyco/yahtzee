#include "scoreCard.h"
#include <iostream>

ScoreCard::ScoreCard(Dice* inArray)
{
   // okay so this should make the vector filled with categories
   // then this should go through the vector and set each of these's dice array up
   // should maybe test if catch null is working too rq

   categories.push_back(new Aces());
   categories.push_back(new Twos());
   categories.push_back(new Threes());
   categories.push_back(new Fours());
   categories.push_back(new Fives());
   categories.push_back(new Sixes());
   categories.push_back(new ThreeOfAKind());
   categories.push_back(new FourOfAKind());
   categories.push_back(new FullHouse());
   categories.push_back(new SmStraight());
   categories.push_back(new LgStraight());
   categories.push_back(new Yahtzee());
   categories.push_back(new Chance());

   // DELETE LATER, TESTING, SHOULD BREAK EVERYTHING
   categories[1]->calculateValue();

   for (int i = 0; i < categories.size(); i++)
   {
      categories[i]->setArrayOfDice(inArray);
   }
}

ScoreCard::~ScoreCard()
{
   // runs while categories has stuff in it
   while (!(categories.empty()))
   {
      delete categories[categories.size() - 1];
      categories.pop_back();
   }

}

int ScoreCard::getUpperTotal()
{
   int upperTotal = 0;

   for (int i = 0; i < categories.size(); i++)
   {
      if ((*categories[i]).getIsUpper())
      {
         upperTotal += categories[i]->getPointValue();
      }
   }

   return upperTotal;

}

int ScoreCard::getLowerTotal()
{
   int lowerTotal = 0;

   for (int i = 0; i < categories.size(); i++)
   {
      if (!((*categories[i]).getIsUpper()))
      {
         lowerTotal += categories[i]->getPointValue();
      }
   }

   return lowerTotal;

}

int ScoreCard::getCombinedTotal()
{
   combinedTotal = upperTotal + lowerTotal;

   return combinedTotal;
   
}

int ScoreCard::getUpperWithBonus()
{
   if (upperTotal > 62)
   {
      upperTotal += BONUS;
   }

   return upperTotal;

}

bool ScoreCard::attemptSetScore(const string& inStr)
{
   for (int i = 0; i < categories.size(); i++)
   {
      if (categories[i]->getCategoryName() == inStr)
      {
         if (!(categories[i]->getHasValue()))
         {
            categories[i]->setPointValue(categories[i]->calculateValue());  
            return true;
         }

         return false;
      }
   }

   return false;
}