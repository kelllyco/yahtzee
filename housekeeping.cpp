#include "housekeeping.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

// set the static values to 0
int Housekeeping::timesSeedSet = 0;

void Housekeeping::setSeed()
{
   // if this has been called before throw an error
   if (timesSeedSet > 0)
   {
      // could probably throw a user defined error here hmmm
      cout<<"DONT RESEED THE RANDOMIZATION"<<endl;
   }

   // otherwise do not throw the error, set the time as needed and iterate timesSeedSet
   else 
   {
      srand(time(0));
      timesSeedSet += 1;
   }  
}
