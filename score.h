#ifndef SCORE
#define SCORE

#include <iostream>
#include "Dice.h"
#include "score.h"

using namespace std;

// abstract base class for the scores
class Score
{
   private:
      // most important piece of info, holds point value for a score
      int pointValue;

      // bool to indicate if a score has been used, impt if user has to put 0 in a category
      bool hasValue = false;

      // private member var to hold passed in array of dice
      Dice* arrayOfDice;

   public:
      // point val getter and setter
      void setPointValue(int);
      int getPointValue();

      // setter and getter for has value
      bool getHasValue();
      void setHasValue(bool); // default value is true   

      // abstract function
      virtual int calculateValue() = 0;

};

// the following are concrete classes for the score class
// they hold a calculate value function which will be different for each class
// they also have their typename, which will never change
class Aces : public Score {
   public:
      Aces(*Dice);

      int calculateValue() override;
      const string TYPENAME = "aces";
};

class Twos : public Score {
   public:
      Twos(*Dice);

      int calculateValue() override;
      const string TYPENAME = "twos";
};

class Threes : public Score {
   public:
      Threes(*Dice);

      int calculateValue() override;
      const string TYPENAME = "threes";
};

class Fours : public Score {
   public:
      Fours(*Dice);

      int calculateValue() override;
      const string TYPENAME = "fours";
};

class Fives : public Score {
   public:
      Fives(*Dice);

      int calculateValue() override;
      const string TYPENAME = "fives";
};

class Sixes : public Score {
   public:
      Sixes(*Dice);

      int calculateValue() override;
      const string TYPENAME = "sixes";
};

class ThreeOfAKind : public Score {
   public:
      ThreeOfAKind(*Dice);

      int calculateValue() override;
      const string TYPENAME = "three of a kind";
};

class FourOfAKind : public Score {
   public:
      FourOfAKind(*Dice);

      int calculateValue() override;
      const string TYPENAME = "four of a kind";
};

class FullHouse : public Score {
   public:
      FullHouse(*Dice);

      int calculateValue() override;
      const string TYPENAME = "full house";
};

class Yahtzee : public Score {
   public:
      Yahtzee(*Dice);

      int calculateValue() override;
      const string TYPENAME = "yahtzee";
};

class Chance : public Score {
   public:
      Chance(*Dice);
      
      int calculateValue() override;
      const string TYPENAME = "chance";
};

#endif