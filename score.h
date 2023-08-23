#ifndef SCORE
#define SCORE

#include <iostream>
#include "diceCup.h"
#include "score.h"

using namespace std;

class Score
{
   private:
      // most important piece of info, holds 
      int pointValue;

      // wont really be needed on backend, but will probably be helpful for frontend
      string category;

      bool hasValue = false;

   public:
      // all just generic getters and setters
      void setPointValue(int);
      int getPointValue();

      void setCategory(string);
      string getCategory();

      bool getHasValue();
      

};

#endif