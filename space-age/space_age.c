#include "space_age.h"

static const float planets[]={
   [MERCURY]=0.2408467,
   [VENUS]=0.61519726,
   [EARTH]=1.0,
   [MARS]=1.8808158,
   [JUPITER]=11.862615,
   [SATURN]=29.447498,
   [URANUS]=84.016846,
   [NEPTUNE]=164.79132,
};

float age(planet_t planet, int64_t seconds){
    if (planet<0 ||planet>7){return -1;}
    static const float y1=31557600;
    // static const becasue then it becomes global variable 
    // and won't be created many times with function use.
    return seconds/y1/planets[planet];
}