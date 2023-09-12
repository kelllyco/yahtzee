#include "/Users/kellycochran/Desktop/yahtzee/include/score.h"

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
   setHasValue();
   pointValue = inInt; 
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

void Score::setArrayOfDice(Dice* inArray)
{
   arrayOfDice = inArray;
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

void Score::checkNull()
{
   try
   {
      if (arrayOfDice == nullptr)
      {
         throw runtime_error("cannot calculate values while an array of dice has not been set\ntry using Score's setArrayOfDice if this error is thrown bc you're trying to use score categories outside of scoreCard");
      }
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
   
   
}

void Score::setIsUpper(bool inBool)
{
   isUpper = inBool;
}

void Score::setCategoryName(string inString)
{
   typeName = inString;
}

bool Score::getIsUpper()
{
   return isUpper;
}

string Score::getCategoryName()
{
   return typeName;
}

// child class calculate value overrides
// some of the calcs could use a retool once I learn more *cough* nested for loop in FullHouse *cough*
// there's def a better way to do that lol
int Aces::calculateValue()
{
   checkNull();
   return helperSum(1);
}

Aces::Aces()
{
   setIsUpper(true);
   setCategoryName("aces");
}

int Twos::calculateValue()
{
   checkNull();
   return helperSum(2);
}

Twos::Twos()
{
   setIsUpper(true);
   setCategoryName("twos");
}

int Threes::calculateValue()
{
   checkNull();
   return helperSum(3);
}

Threes::Threes()
{
   setIsUpper(true);
   setCategoryName("threes");
}

int Fours::calculateValue()
{
   checkNull();
   return helperSum(4);
}

Fours::Fours()
{
   setIsUpper(true);
   setCategoryName("fours");
}

int Fives::calculateValue()
{
   checkNull();
   return helperSum(5);
}

Fives::Fives()
{
   setIsUpper(true);
   setCategoryName("fives");
}

int Sixes::calculateValue()
{
   checkNull();
   return helperSum(6);
}

Sixes::Sixes()
{
   setIsUpper(true);
   setCategoryName("sixes");
}

int ThreeOfAKind::calculateValue()
{
   checkNull();

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

ThreeOfAKind::ThreeOfAKind()
{
   setIsUpper(false);
   setCategoryName("three of a kind");
}

int FourOfAKind::calculateValue()
{
   checkNull();

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

FourOfAKind::FourOfAKind()
{
   setIsUpper(false);
   setCategoryName("four of a kind");
}

int FullHouse::calculateValue()
{
   checkNull();

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

FullHouse::FullHouse()
{
   setIsUpper(false);
   setCategoryName("full house");
}

int SmStraight::calculateValue()
{
   checkNull();

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

SmStraight::SmStraight()
{
   setIsUpper(false);
   setCategoryName("small straight");
}

int LgStraight::calculateValue()
{
   checkNull();

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

LgStraight::LgStraight()
{
   setIsUpper(false);
   setCategoryName("large straight");
}

int Yahtzee::calculateValue()
{
   checkNull();

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

Yahtzee::Yahtzee()
{
   setIsUpper(false);
   setCategoryName("yahtzee");
}

int Chance::calculateValue()
{
   checkNull();
   
   return addAll();
}

Chance::Chance()
{
   setIsUpper(false);
   setCategoryName("chance");
}