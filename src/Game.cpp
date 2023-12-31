#include "../include/Game.h"

Game::Game(DiceCup *d)
{
   currentCup = d;
}

void Game::welcomeMessage(const ScoreCard* currentPlayer)
{
   string junk;
   system("clear");
   cout<<"---- Yahtzee ----\n\n";

   cout<<"Yahtzee is a dice game where players roll five dice and aim\nto achieve specific combinations for points. It requires both luck\nand strategic decision making.\n\n";

   cout<<"This simulation of Yahtzee currently only supports one player.\nCheck back soon for updates (or even a computer to play against)!\n\n";

   cout<<"For more information, including the rules of the game,\nplease visit the following link:\nhttps://www.hasbro.com/common/instruct/yahtzee.pdf\n\n";

   cout<<"Please press the return key to continue.\n\n";

   getline(cin, junk);
   system("clear");

   cout<<"Here's a look at the scoreboard that you'll be filling up.\n\nRemember, to get a bonus, you must have an upper\nsection score of 36 or higher!\n\n";

   currentPlayer->OUTPUTCATEGORIES();

   cout<<"\n\nWhen you're ready to add the dice to the cup and begin the game, press the return key!\n\n";
   getline(cin, junk);

}

bool Game::selectDice()
{
   bool continueGame = false;

   if (currentCup->timesRolled > 2)
   {
      return continueGame;
   }
   cout<<"\nGreat! To continue, please enter the index of each\ndie you would like to roll again, separated by spaces,\nand press return when you have finished.\n\n";
   cout<<"If you would like to end your turn here, simply press return.\n\n";
   
   char charDice;

   // runs while a newline is not read in
   do {
      
      charDice = cin.get();
      charDice = toupper(charDice);

      if (!((charDice == '\n') || (charDice == ' ')))
      {
         // casts the char to an int and accounts for ascii translation
         int inDice = (static_cast<int>(charDice) - 65);

         // adds to cup to be rolled
         (*currentCup).addToCup(inDice);
         continueGame = true;
      }

   } while (charDice != '\n');

   cout<<endl;
   return continueGame;

}

void Game::rollAndOutput()
{
   cout<<"The dice have successfully added to the cup! Press the return\nkey to roll them out and view your results.\n\n";

   string junk;
   getline(cin, junk);

   system("clear");

   // rolls the dice that are in the rolling cup
   (*currentCup).roll();

   // reads off the current dice info to the user
   cout<<"--- Roll "<<(*currentCup).timesRolled<<"/3 ---"<<endl<<endl;
   for (int i = 0; i < 5; i++)
   {
      cout<<"Dice "<<static_cast<char>(i+65)<<" -- "<<(*currentCup).diceArray[i].getCurrentValue()<<endl;
   }

   cout<<endl;
}

void Game::whichCategory(ScoreCard* currentPlayer)
{
   cout<<"Your turn is now over! Enter the lowercase name of the\ncategory you would like to apply this turn to."<<endl<<endl;

   string userCategory;
   getline(cin, userCategory);

   bool validCategory = currentPlayer->attemptSetScore(userCategory);

   // only enters if first attempt to select a category failed
   while (!validCategory)
   {
      cout<<"\nInvalid category! There are a few reasons that this might be happening:\n\t- You're applying a score to an already used category\n\t- You entered the category name in incorrectly"<<endl<<endl;
      cout<<"Let's try again below.\n\n";

      getline(cin, userCategory);

      validCategory = currentPlayer->attemptSetScore(userCategory);
   }

   system("clear");
}

void Game::nextTurn(const ScoreCard* currentPlayer)
{
   string junk;
   cout<<"Here's a look at where things stand following your turn...\n\n\n";
   cout<<endl<<"--- CURRENT SCORES ---"<<endl<<endl;
   currentPlayer->OUTPUTCATEGORIES();

   cout<<"Press the return key when you're ready to add the dice back to the cup.\n\n";
   getline(cin, junk);
   currentCup->resetTimesRolled();

   for (int i = 0; i < 5; i++)
   {
      currentCup->addToCup(i);
   }
}

void Game::endOfGame(ScoreCard* currentPlayer)
{
   cout<<endl<<"--- FINAL SCORECARD ---"<<endl<<endl;
   currentPlayer->OUTPUTCATEGORIES();

   cout<<"UPPER SUBTOTAL:\t"<<currentPlayer->getUpperTotal()<<endl;

   if (currentPlayer->getUpperTotal() > 62)
   {
      cout<<"BONUS:\t35"<<endl;
   }
   else
   {
      cout<<"BONUS:\t0"<<endl;
   }

   cout<<"UPPER TOTAL:\t"<<currentPlayer->getUpperWithBonus()<<endl;
   cout<<"LOWER TOTAL:\t"<<currentPlayer->getLowerTotal()<<endl<<endl;

   cout<<"FINAL SCORE:\t"<<currentPlayer->getCombinedTotal()<<endl<<endl;
   

}