#include "../include/scoreCard.h"

ScoreCard::ScoreCard(Dice* inArray)
{
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
   upperTotal = 0;

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
   lowerTotal = 0;

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
      upperTotal += 35;
   }

   return upperTotal;

}

bool ScoreCard::attemptSetScore(const string& inStr)
{
   for (int i = 0; i < categories.size(); i++)
   {
      // if the entered name is a valid cat
      if (categories[i]->getCategoryName() == inStr)
      {
         // if it doesnt already have a value, go ahead and calc and set one
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

void ScoreCard::OUTPUTCATEGORIES() const
{
   cout<<"UPPER SECTION\n";
   for (int i = 0; i < categories.size(); i++)
   {
      if (i == 6)
      {
         cout<<endl<<"LOWER SECTION\n";
      }
      cout<<categories[i]->getCategoryName()<<": ";
      if (categories[i]->getHasValue())
      {
         cout<<categories[i]->getPointValue()<<endl;
      }
      else
      {
         cout<<endl;
      }
      
   }

   cout<<endl;
}