#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include "Dice.h"


using namespace std;

// abstract base class for the scores
class Score
{
   private:
      // most important piece of info, holds point value for a score
      int pointValue;

      // bool to indicate if a score has been used, impt if user has to put 0 in a category
      bool hasValue = false;


   protected:
      // protected memb var to hold passed in dice array pointer (passed in from child)
      Dice* arrayOfDice;

      // takes in num to find, returns the value of that num times its occurences in the array
      int helperSum(int);

      // fills and array that has the number of times each roll shows up, returns nothing
      void fillCounter();

      // the array that is filled by fillCounter method
      int counter[6] = {0, 0, 0, 0, 0, 0};

      // clears counter
      void clearCounter();

      // adds the sum of the dice in the array
      int addAll();

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
      Aces(Dice*);

      int calculateValue() override;
      const string TYPENAME = "aces";
};

class Twos : public Score {
   public:
      Twos(Dice*);

      int calculateValue() override;
      const string TYPENAME = "twos";
};

class Threes : public Score {
   public:
      Threes(Dice*);

      int calculateValue() override;
      const string TYPENAME = "threes";
};

class Fours : public Score {
   public:
      Fours(Dice*);

      int calculateValue() override;
      const string TYPENAME = "fours";
};

class Fives : public Score {
   public:
      Fives(Dice*);

      int calculateValue() override;
      const string TYPENAME = "fives";
};

class Sixes : public Score {
   public:
      Sixes(Dice*);

      int calculateValue() override;
      const string TYPENAME = "sixes";
};

class ThreeOfAKind : public Score {
   public:
      ThreeOfAKind(Dice*);

      int calculateValue() override;
      const string TYPENAME = "three of a kind";
};

class FourOfAKind : public Score {
   public:
      FourOfAKind(Dice*);

      int calculateValue() override;
      const string TYPENAME = "four of a kind";
};

class FullHouse : public Score {
   public:
      FullHouse(Dice*);

      int calculateValue() override;
      const string TYPENAME = "full house";
};

class SmStraight : public Score {
   public:
      SmStraight(Dice*);

      int calculateValue() override;
      const string TYPENAME = "small straight";
};

class LgStraight : public Score {
   public:
      LgStraight(Dice*);

      int calculateValue() override;
      const string TYPENAME = "large straight";
};

class Yahtzee : public Score {
   public:
      Yahtzee(Dice*);

      int calculateValue() override;
      const string TYPENAME = "yahtzee";
};

class Chance : public Score {
   public:
      Chance(Dice*);

      int calculateValue() override;
      const string TYPENAME = "chance";
};

#endif