#include "housekeeping.h"
#include "diceCup.h"
#include "Dice.h"
#include "Game.h"
#include "scoreCard.h"
#include "calculator.h"

#include <iostream>

using namespace std;

int main() {

   Housekeeping h;

   h.setSeed();

   DiceCup *d = new DiceCup;

   Game g = Game(d);

   ScoreCard s = ScoreCard(d->dangerReturnsDiceArrayPtr());

   g.welcomeMessage();

   bool ctndCurrentTurn = false;

   do
   {
      // rolls the dice, lets the user know what the outcome is
      g.rollAndOutput();

      // asks the user if they want to roll again, will contintue to ask until they enter the right thing
      // wont allow the user to roll again if they're out of rolls
      ctndCurrentTurn = g.rollAgain();

      // if they want to go again, will ask which dice they want to re roll
      if (ctndCurrentTurn)
      {
         g.selectDice();
      }

   } 
   while (ctndCurrentTurn);

   // asks the user which category they want to apply their turn to
   g.whichCategory(s);
   
   



   // cout<<"value of aces is: "<<c.calcAces()<<endl;
   // cout<<"value of twos is: "<<c.calcTwos()<<endl;
   // cout<<"value of threes is: "<<c.calcThrees()<<endl;
   // cout<<"value of fours is: "<<c.calcFours()<<endl;
   // cout<<"value of fives is: "<<c.calcFives()<<endl;
   // cout<<"value of sixes is: "<<c.calcSixes()<<endl;
   // cout<<endl;
   // cout<<"value of three of a kind is: "<<c.calcThreeOfAKind()<<endl;
   // cout<<"value of four of a kind is: "<<c.calcFourOfAKind()<<endl;
   // cout<<"value of full house is: "<<c.calcFullHouse()<<endl;
   // cout<<"value of sm straight is: "<<c.calcSmStraight()<<endl;
   // cout<<"value of lg straight is: "<<c.calcLgStraight()<<endl;
   // cout<<"value of yahtzee is: "<<c.calcYahtzee()<<endl;
   // cout<<"value of chance is: "<<c.calcChance()<<endl;
   // cout<<endl;


   //g.userSelection();



   // g.rollAndOutput();
   // g.userSelection();

   // g.rollAndOutput();
   // g.userSelection();
   
   delete d;
   d = nullptr;
   

}