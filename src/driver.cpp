#include "../include/housekeeping.h"
#include "../include/diceCup.h"
#include "../include/Game.h"
#include "../include/scoreCard.h"

#include <iostream>

using namespace std;

int main() {

   // sets the seed
   Housekeeping h;
   h.setSeed();

   // dynamically allocates a dicecup obj, which creates dice objs too
   DiceCup *cupOfDice = new DiceCup;

   // creates a game based off of the current dicecup obj
   // makes sense bc theres only one cup of dice in the game, everyone shares
   Game output = Game(cupOfDice);

   // dynamically allocates a scorecard for the player, which also creates scores and categories
   // takes in dice array ptr so child category calculators know what to calculate
   ScoreCard *player1 = new ScoreCard(cupOfDice->dangerReturnsDiceArrayPtr());

   // welcomes the player
   output.welcomeMessage(player1);
   bool ctndCurrentTurn;

   // runs for the amount of turns in a game
   for (int i = 0; i < 13; i++)
   {
      ctndCurrentTurn = false;

      do
      {
         // rolls the dice, lets the user know what the outcome is
         output.rollAndOutput();

         ctndCurrentTurn = output.selectDice(); // force returns false if youve had 3 rolls
      } 
      while (ctndCurrentTurn);

      // asks the user which category they want to apply their turn to
      output.whichCategory(player1);
      
      // resets stuff for the next turn
      output.nextTurn(player1);
   }

   // puts together and outputs final scores
   output.endOfGame(player1);
   
   // deallocates dynamically allocated memory
   delete cupOfDice;
   cupOfDice = nullptr;

   delete player1;
   player1 = nullptr;
   

}