#ifndef SCORE
#define SCORE

#include <iostream>
#include "diceCup.h"
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

class Aces : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "aces";
};

class Twos : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "twos";
};

class Threes : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "threes";
};

class Fours : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "fours";
};

class Fives : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "fives";
};

class Sixes : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "sixes";
};

class ThreeOfAKind : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "three of a kind";
};

class FourOfAKind : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "four of a kind";
};

class FullHouse : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "full house";
};

class Yahtzee : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "yahtzee";
};

class Chance : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "chance";
};

#endif