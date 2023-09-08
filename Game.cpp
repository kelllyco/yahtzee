#include <iostream>
#include <ctype.h>
#include "Game.h"
#include "diceCup.h"
#include "Dice.h"


Game::Game(DiceCup *d)
{
   currentCup = d;
}

void Game::welcomeMessage()
{
   cout<<"Welcome to Yahtzee!\n\nYou know how to play! Just be sure to read the instructions carefully, because if you enter a wonky character, the game might break :)\n\n";

   cout<<"Alrighty, time to roll the dice for the first time!"<<endl<<endl;

}

bool Game::rollAgain()
{
   // if the dice has been rolled too many times, dont bother with any of this
   if ((*currentCup).timesRolled > 2)
   {
      return false;
   }
   // prompts user
   cout<<"Are you happy with the results of this roll, or would you like to roll again?\nYou have "<<3 - (*currentCup).timesRolled<<" rolls remaining."<<endl;
   cout<<"If you would like to roll again, enter 'y' followed by the return key, if not, enter 'n' followed by the return key."<<endl;

   // inits userInput
   char userInput = ' ';

   cin>>userInput;

   // enters loop and stays in while y or n are not entered
   while (!((userInput == 'y') || (userInput == 'n')))
   {
      cout<<"You entered an invalid choice! Please try again."<<endl;
      cin>>userInput;
   }

   fflush(stdin);

   // if the user entered y, return true, otherwise do nothing
   if (userInput == 'y')
   {
      return true;
   }

   return false;

}

void Game::selectDice()
{
   cout<<"Time to add the dice to the cup to be re-rolled!"<<endl<<endl<<"Be sure to enter integer value(s), ex '1 4 5' to have the first, fourth, and fifth dice rolled."<<endl<<endl;
   cout<<"When you've finished adding your dice to the cup, press enter."<<endl;

   char charDice;

   cout<<endl<<endl<<"Which number dice would you like to roll? ";

   // runs while a newline is not read in
   do {
      
      charDice = cin.get();

      if (!((charDice == '\n') || (charDice == ' ')))
      {
         // casts the char to an int and accounts for ascii translation
         int inDice = (static_cast<int>(charDice) - 49);

         // adds to cup to be rolled
         (*currentCup).addToCup(inDice);
      }

   } while (charDice != '\n');

}

void Game::rollAndOutput()
{
   // rolls the dice that are in the rolling cup
   (*currentCup).roll();

   // reads off the current dice info to the user
   cout<<"Following roll #"<<(*currentCup).timesRolled<<", these are the dice values..."<<endl<<endl;
   for (int i = 0; i < 5; i++)
   {
      cout<<"\tThe value of dice #"<<i+1<<" is: "<<(*currentCup).diceArray[i].getCurrentValue()<<endl;
   }

   cout<<endl;
}

void Game::whichCategory(ScoreCard currentPlayer)
{
   cout<<"Your turn is now over! Which category would you like to apply your cup of dice to?"<<endl;
   cout<<"Please type in the category name in all lower case"<<endl;

   string userCategory;
   getline(cin, userCategory);

   bool validCategory = currentPlayer.attemptSetScore(userCategory);

   while (!validCategory)
   {
      cout<<"Invalid category! This could be happening because you entered an incorrect category name, or because you tried to assign a score to a category that already has one."<<endl;
      cout<<"Please try again below."<<endl;

      getline(cin, userCategory);
      validCategory = currentPlayer.attemptSetScore(userCategory);
   }
}