#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  // hsv to rgb formula acquired from: https://www.rapidtables.com/convert/color/hsv-to-rgb.html
  
  double c = v * s;
  double x = c * (1 - std::abs(std::fmod(h/60,2) - 1));
  double m = v - c;

  if (0 <= h && h < 60){
    r = c;
    g = x;
    b = 0;
  } else if (60 <= h && h < 120){
    r = x;
    g = c;
    b = 0;
  } else if (120 <= h && h < 180){
    r = 0;
    g = c;
    b = x;
  } else if (180 <= h && h < 240){
    r = 0;
    g = x;
    b = c;
  } else if (240 <= h && h < 300){
    r = x;
    g = 0;
    b = c;
  } else if (300 <= h && h < 360){
    r = c;
    g = 0;
    b = x;
  }     
}
