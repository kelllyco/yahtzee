#include "scoreCard.h"
#include "calculator.h"
#include <iostream>

int ScoreCard::bonus = 35;

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
      upperTotal += bonus;
   }

   return upperTotal;

}

// basically just one long switch statement
Score ScoreCard::getScoreObj(int inNum)
{
   switch (inNum)
   {
      case 1:
         return aces;
         break;
      case 2:
         return twos;
         break;
      case 3:
         return threes;
         break;
      case 4:
         return fours;
         break;
      case 5:
         return fives;
         break;
      case 6:
         return sixes;
         break;
      case 7:
         return threeOfAKind;
         break;
      case 8:
         return fourOfAKind;
         break;
      case 9:
         return fullHouse;
         break;
      case 10:
         return smStraight;
         break;
      case 11:
         return lgStraight;
         break;
      case 12:
         return yahtzee;
         break;
      case 13:
         return chance;
         break;
      default:
         cout<<"ERROR IN SWITCH"<<endl;
   }

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