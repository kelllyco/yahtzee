#include "score.h"

// getters and setters
bool Score::getHasValue()
{
   return hasValue;
}

void Score::setHasValue(bool inBool = true)
{
   hasValue = inBool;
}

void Score::setPointValue(int inInt)
{
   pointValue = inInt;
   hasValue = true;
}

int Score::getPointValue()
{
   return pointValue;
}



