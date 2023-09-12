#include "../include/diceCup.h"

DiceCup::DiceCup()
{
   timesRolled = 0;

   // works since size of cupArray is hardcoded to 5
   for (int i = 0; i < 5; i++)
   {
      diceArray[i] = Dice();
   }

}

Dice* DiceCup::dangerReturnsDiceArrayPtr()
{
   return diceArray;
}


void DiceCup::addToCup(int diceIndex)
{
   cupOfDice.push_back(diceIndex);
}


int DiceCup::removeFromCup()
{
   int heldIndex;

   // get the index held at the back of the vector
   heldIndex = cupOfDice[cupOfDice.size() - 1];

   // get rid of the end of the vector
   cupOfDice.pop_back();

   return heldIndex;

}

void DiceCup::roll()
{
   if (timesRolled < 3)
   {
      int amntToRoll = cupOfDice.size();

      // runs loop for number of dice needed to roll
      for (int i = 0; i < amntToRoll; i++)
      {
         diceArray[removeFromCup()].rollDice();
      }

      timesRolled += 1;
   }
}

void DiceCup::resetTimesRolled()
{
   timesRolled = 0;
}