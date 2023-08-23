#include "score.h"

using namespace std;

// getters and setters
bool Score::getHasValue()
{
   return hasValue;
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

void Score::setCategory(string inString)
{
   category = inString;
}

string Score::getCategory()
{
   return category;
}



