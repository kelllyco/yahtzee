// this file contains the function, constructor, and variable definitions for the housekeeping class
// it can be included in other files to allow the housekeeping class to be utilized inside of them

#ifndef HOUSEKEEPING_H
#define HOUSEKEEPING_H

// okay so i recognize that the use of static here is probably very undesireable, but i needed a way to essentially fake a global variable
// reasons for this:
// 1. global variables are bad
// 2. i only wanted seed to be called once, and i reallly didnt want to do it at the beginning of my driver and pass it into each lower function that i call
// 3. if it wasn't static, i could end up with seed getting called each time a new housekeeping variable is made
// 3. because i would like to avoid this, the variable needs to be shared across the entire class
// 3. you might ask, why just not create a new housekeeping object multiple times?
// 3. my answer is basically that i'm still in the early stages of creating this program and i'm not certain which parts are going to be repeated or not yet
// 3. i'd rather create a backdoor solution now and maybe come back to it, but one that will nevertheless work, instead of just plopping something in that could mess me up later

class Housekeeping
{
   public:
      // function to be called once, will use ctime to set the seed for rolling randomization
      static void setSeed();

   private:
      static int timesSeedSet;
};


#endif