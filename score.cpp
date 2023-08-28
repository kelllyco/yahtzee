#include "score.h"

// getters and setters
bool Score::getHasValue()
{
   return hasValue;
}

void Score::setHasValue(bool inBool = true)
{
   hasValue = inBool;
}

void Score::setPointValue(int inInt)
{
   pointValue = inInt;
   hasValue = true;
}

int Score::getPointValue()
{
   return pointValue;
}

void Score::fillCounter()
{
   clearCounter();

   for (int i = 0; i < 5; i++)
   {
      counter[arrayOfDice[i].getCurrentValue() - 1] += 1;
   }
}

void Score::clearCounter()
{
   for (int i = 0; i < 6; i++)
   {
      counter[i] = 0;
   }
}

int Score::helperSum(int num)
{
   int output = 0;

   // runs through and outputs the sum of each dice of a certain value
   for (int i = 0; i < 5; i++)
   {
      if (arrayOfDice[i].getCurrentValue() == num)
      {
         output += num;
      }
   }

   return output;

}

int Score::addAll()
{
   int output = 0;

   for (int i = 0; i < 5; i++)
   {
      output += arrayOfDice[i].getCurrentValue();
   }

   return output;
}

// child class constructors and calculate value overrides
// some of the calcs could use a retool once I learn more *cough* nested for loop in FullHouse *cough*
Aces::Aces(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Aces::calculateValue()
{
   return helperSum(1);
}

Twos::Twos(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Twos::calculateValue()
{
   return helperSum(2);
}

Threes::Threes(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Threes::calculateValue()
{
   return helperSum(3);
}

Fours::Fours(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Fours::calculateValue()
{
   return helperSum(4);
}

Fives::Fives(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Fives::calculateValue()
{
   return helperSum(5);
}

Sixes::Sixes(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int Sixes::calculateValue()
{
   return helperSum(6);
}

ThreeOfAKind::ThreeOfAKind(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int ThreeOfAKind::calculateValue()
{
   fillCounter();

   for (int i = 0; i < 6; i++)
   {
      if (counter[i] > 2)
      {
         return addAll();
      }
   }

   return 0;
}

FourOfAKind::FourOfAKind(Dice* inArray) : Score() 
{
   arrayOfDice = inArray;
}

int FourOfAKind::calculateValue()
{
   fillCounter();

   for (int i = 0; i < 6; i++)
   {
      if (counter[i] > 3)
      {
         return addAll();
      }
   }

   return 0;
}

FullHouse::FullHouse(Dice* inArray) : Score()
{
   arrayOfDice = inArray;
}

int FullHouse::calculateValue()
{
   fillCounter();

   for (int i = 0; i < 6; i++)
   {
      // if there is a index two or higher
      if (counter[i] > 1)
      {
         // check to see if its three
         if (counter[i] > 2)
         {
            // since have three, continue to check through for a two
            for (int j = (i + 1); j < 6; j++)
            {
               if (counter[j] > 1)
               {
                  return 25;
               }
            }
         }

         // if here, you have a two, continue searching for a three
         else 
         {
            for (int j = (i + 1); j < 6; j++)
            {
               if (counter[j] > 2)
               {
                  return 25;
               }
            }
         }

      }
   }

   // if it gets this far without returning and exiting the function, a 2 and 3 weren't found
   return 0;
}

SmStraight::SmStraight(Dice* inArray) : Score()
{
   arrayOfDice = inArray;
}

int SmStraight::calculateValue()
{
   fillCounter();

   if ((counter[0] > 0) && (counter[1] > 0) && (counter[2] > 0) && (counter[3] > 0))
   {
      return 30;
   }
   else if ((counter[4] > 0) && (counter[1] > 0) && (counter[2] > 0) && (counter[3] > 0))
   {
      return 30;
   }
   else if ((counter[4] > 0) && (counter[5] > 0) && (counter[2] > 0) && (counter[3] > 0))
   {
      return 30;
   }
   else
   {
      return 0;
   }
}

LgStraight::LgStraight(Dice* inArray) : Score()
{
   arrayOfDice = inArray;
}

int LgStraight::calculateValue()
{
   fillCounter();

   if ((counter[0] > 0) && (counter[1] > 0) && (counter[2] > 0) && (counter[3] > 0) && (counter[4] > 0))
   {
      return 40;
   }
   else if ((counter[5] > 0) && (counter[1] > 0) && (counter[2] > 0) && (counter[3] > 0) && (counter[4] > 0))
   {
      return 40;
   }
   else
   {
      return 0;
   }
}

Yahtzee::Yahtzee(Dice* inArray) : Score()
{
   arrayOfDice = inArray;
}

int Yahtzee::calculateValue()
{
   fillCounter();

   for (int i = 0; i < 6; i++)
   {
      if (counter[i] == 5)
      {
         return 50;
      }
   }

   return 0;
}

Chance::Chance(Dice* inArray) : Score()
{
   arrayOfDice = inArray;
}

int Chance::calculateValue()
{
   return addAll();
}