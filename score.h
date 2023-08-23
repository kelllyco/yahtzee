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

};

#endif