#include "/Users/kellycochran/Desktop/yahtzee/include/housekeeping.h"
#include "/Users/kellycochran/Desktop/yahtzee/include/diceCup.h"
#include "/Users/kellycochran/Desktop/yahtzee/include/Dice.h"
#include "/Users/kellycochran/Desktop/yahtzee/include/Game.h"
#include "/Users/kellycochran/Desktop/yahtzee/include/scoreCard.h"

#include <iostream>

using namespace std;

int main() {

   Housekeeping h;

   h.setSeed();

   DiceCup *d = new DiceCup;

   Game g = Game(d);

   ScoreCard *s = new ScoreCard(d->dangerReturnsDiceArrayPtr());

   g.welcomeMessage(s);
   bool ctndCurrentTurn;

   for (int i = 0; i < 13; i++)
   {
      ctndCurrentTurn = false;

      do
      {
         // rolls the dice, lets the user know what the outcome is
         g.rollAndOutput();

         ctndCurrentTurn = g.selectDice();
      } 
      while (ctndCurrentTurn);

      // asks the user which category they want to apply their turn to
      g.whichCategory(s);
      
      g.nextTurn(s);
   }



   
   delete d;
   d = nullptr;

   delete s;
   s = nullptr;
   

}