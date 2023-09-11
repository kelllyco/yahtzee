#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <stdexcept>
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

      bool isUpper;

      string typeName;


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

      // pings if the scores try to calculate values while arrayOfDice is null
      void checkNull();

      // setters for child class vals
      void setIsUpper(bool);
      void setCategoryName(string);
      

   public:
      // setter for the array of dice, for use in the scorecard constructor
      void setArrayOfDice(Dice*);

      // setter and getter for has value
      bool getHasValue();
      void setHasValue(bool); // default value is true   

      // abstract function
      virtual int calculateValue() = 0;

      // getters for child class vals
      void setPointValue(int);
      int getPointValue();
      bool getIsUpper();
      string getCategoryName();

      // add this to not have an illegal instruction error!
      virtual ~Score() = default;


};

// the following are concrete classes for the score class
// they hold a calculate value function which will be different for each class
// they also have their typename, which will never change
class Aces : public Score {
   public:
      int calculateValue() override;
      Aces();
};

class Twos : public Score {
   public:
      int calculateValue() override;
      Twos();
};

class Threes : public Score {
   public:
      int calculateValue() override;
      Threes();
};

class Fours : public Score {
   public:
      int calculateValue() override;
      Fours();
};

class Fives : public Score {
   public:
      int calculateValue() override;
      Fives();
};

class Sixes : public Score {
   public:
      int calculateValue() override;
      Sixes();
};

class ThreeOfAKind : public Score {
   public:
      int calculateValue() override;
      ThreeOfAKind();
};

class FourOfAKind : public Score {
   public:
      int calculateValue() override;
      FourOfAKind();
};

class FullHouse : public Score {
   public:
      int calculateValue() override;
      FullHouse();
};

class SmStraight : public Score {
   public:
      int calculateValue() override;
      SmStraight();
};

class LgStraight : public Score {
   public:
      int calculateValue() override;
      LgStraight();
};

class Yahtzee : public Score {
   public:
      int calculateValue() override;
      Yahtzee();
};

class Chance : public Score {
   public:
      int calculateValue() override;
      Chance();
};

#endif