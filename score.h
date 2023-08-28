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
      // one might ask why i put this here and i put the ISUPPER in the child classes
      // pride and stubbornness
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

      // pings if the scores try to calculate values while arrayOfDice is null
      void checkNull();

   public:
      // point val getter and setter
      void setPointValue(int);
      int getPointValue();

      // setter for the array of dice, for use in the scorecard constructor
      void setArrayOfDice(Dice*);

      // my number one boy moment
      virtual bool getIsUpper() = 0;

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
      int calculateValue() override;
      const string TYPENAME = "aces";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class Twos : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "twos";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class Threes : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "threes";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class Fours : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "fours";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class Fives : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "fives";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class Sixes : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "sixes";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = true; 
};

class ThreeOfAKind : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "three of a kind";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class FourOfAKind : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "four of a kind";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class FullHouse : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "full house";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class SmStraight : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "small straight";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class LgStraight : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "large straight";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class Yahtzee : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "yahtzee";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

class Chance : public Score {
   public:
      int calculateValue() override;
      const string TYPENAME = "chance";
      bool getIsUpper() override;

   private:
      const bool ISUPPER = false; 
};

#endif