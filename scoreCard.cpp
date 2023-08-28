#include "scoreCard.h"
#include <iostream>

ScoreCard::ScoreCard(Dice* inArray)
{
   // okay so this should make the vector filled with categories
   // then this should go through the vector and set each of these's dice array up
   // should maybe test if catch null is working too rq
}

int ScoreCard::getUpperTotal()
{
   upperTotal = aces.getPointValue() + twos.getPointValue() + threes.getPointValue() + fours.getPointValue() + fives.getPointValue() + sixes.getPointValue();

   return upperTotal;

}

int ScoreCard::getLowerTotal()
{
   lowerTotal = threeOfAKind.getPointValue() + fourOfAKind.getPointValue() + fullHouse.getPointValue() + smStraight.getPointValue() + lgStraight.getPointValue() + yahtzee.getPointValue() + chance.getPointValue();

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

// 
bool ScoreCard::setScoreVal(int categoryNum)
{
   // if the chosen category has already been chosen, return false
   if (getScoreObj(categoryNum).getHasValue())
   {
      return false;
   }

   // otherwise, open a calc object and apply as necessary argh this is getting messy
}