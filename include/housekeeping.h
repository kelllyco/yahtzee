// this class literally just sets the seed for the random function, its a seperate class because i wanted to
// be certain that i wouldn't accidentally call it twice, and this seemed like the safest solution

#ifndef HOUSEKEEPING_H
#define HOUSEKEEPING_H

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class Housekeeping
{
   public:
      // function to be called once, will use ctime to set the seed for rolling randomization
      static void setSeed();

};


#endif