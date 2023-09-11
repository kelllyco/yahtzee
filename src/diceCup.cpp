#include "/Users/kellycochran/Desktop/yahtzee/include/diceCup.h"
#include "/Users/kellycochran/Desktop/yahtzee/include/Dice.h"

#include <iostream>

using namespace std;

// default declaration should init five dice and add them to the array
// init does not roll, have to do the first actual roll as you would in the game irl
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

// adds the index to the vector, while checking to make sure dice cup is not overfilled
void DiceCup::addToCup(int diceIndex)
{
   bool duplicate = false;

   for (int i = 0; i < diceIndexesVector.size(); i++)
   {
      if (diceIndexesVector[i] == diceIndex)
      {
         duplicate = true;
      }
   }

   // tbh this is probably overkill bc some of these instances cant happen due to other ones
   // but better safe than sorry
   if (duplicate)
   {
      cout<<"Cannot add a dice that's already been added to the cup!"<<endl;

   }
   else if ((diceIndex < 0) || (diceIndex > 4))
   {
      cout<<"Cannot add the "<<diceIndex<<" number dice, there are only 5 in the game!"<<endl;
   }
   else if (diceIndexesVector.size() > 4)
   {
      cout<<"Cannot add more dice to cup, there are only 5 in the game!"<<endl;
   }
   else
   {
      diceIndexesVector.push_back(diceIndex);
   }
   
}

// returns the held index at the top of the vector and pops off the element (if thinking of as a stack)
int DiceCup::removeFromCup()
{
   int heldIndex = -1;

   // if its empty, alert and return -1
   if (diceIndexesVector.empty())
   {
      cout<<"Cannot remove dice from an empty cup!"<<endl;
      return heldIndex;
   }

   // get the index held at the back of the vector
   heldIndex = diceIndexesVector[diceIndexesVector.size() - 1];

   // get rid of the end of the vector
   diceIndexesVector.pop_back();

   return heldIndex;

}

// rolls the dice in the cup, also removes them and all so that's handled
// should leave the user with an empty cup (aka an empty diceIndexesVector)
void DiceCup::roll()
{
   if (timesRolled < 3)
   {
      int amntToRoll = diceIndexesVector.size();

      // runs loop for number of dice needed to roll
      for (int i = 0; i < amntToRoll; i++)
      {
         diceArray[removeFromCup()].rollDice();
      }

      timesRolled += 1;
   }
   else
   {
      cout<<"Rolled too many times, you cant roll more than three times!"<<endl;
   }
}

void DiceCup::resetTimesRolled()
{
   timesRolled = 0;
}