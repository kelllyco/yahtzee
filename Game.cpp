#include <iostream>
#include <ctype.h>
#include "Game.h"
#include "diceCup.h"
#include "Dice.h"

// constructor for game, has to take in a pointer to the current set of dice being worked with
Game::Game(DiceCup *d)
{
   currentCup = d;
}

// just prompts the user
void Game::welcomeMessage()
{
   cout<<"Welcome to Yahtzee!\n\nYou know how to play! Just be sure to read the instructions carefully, because if you enter a wonky character, the game might break :)\n\n";

   cout<<"Alrighty, time to roll the dice for the first time!"<<endl<<endl;

}

// determines if user wants to roll again (if thats even possible)
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

// prompts the user to enter dice, giving instructions and has error checking built in
void Game::userSelection()
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

// rolls the dice in the cup, outputs what's going on
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

// returns a number that can be taken in by scorecard which allows the program to know which category the user wants to use the roll for
int Game::selectCategory()
{
   string userCategory;

   int categoryNum = 0;

   cout<<"Which scoring category would you like this turn to count for?\n\nPlease enter the name of the category and then press enter."<<endl;
   
   categoryNum = cin.get();

   while (categoryNum == 0)
   {
      // goes ahead and makes everything lower
      for (int i = 0; i < userCategory.size(); i++)
      {
         userCategory[i] = tolower(userCategory[i]);
      }

      // use this branch bc its less dangerous than passing the pointer to the string, even though it does add an extra step
      // basically just checks for the users input, will ru
      if (userCategory == "aces")
      {
         categoryNum = 1;
      }
      else if (userCategory == "twos")
      {
         categoryNum = 2;
      }
      else if (userCategory == "threes")
      {
         categoryNum = 3;
      }
      else if (userCategory == "fours")
      {
         categoryNum = 4;
      }
      else if (userCategory == "fives")
      {
         categoryNum = 5;
      }
      else if (userCategory == "sixes")
      {
         categoryNum = 6;
      }
      else if (userCategory == "three of a kind")
      {
         categoryNum = 7;
      }
      else if (userCategory == "four of a kind")
      {
         categoryNum = 8;
      }
      else if (userCategory == "full house")
      {
         categoryNum = 9;
      }
      else if (userCategory == "small straight")
      {
         categoryNum = 10;
      }
      else if (userCategory == "large straight")
      {
         categoryNum = 11;
      }
      else if (userCategory == "yahtzee")
      {
         categoryNum = 12;
      }
      else if (userCategory == "chance")
      {
         categoryNum = 13;
      }
      else
      {
         cout<<"\n The category you entered does not exist. Please try again, and dont forget to check your spelling!"<<endl;

         userCategory = cin.get();
      }
   }

   return categoryNum;
   
}