#include "rgb_to_hsv.h"
#include <cmath>
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  // rgb to hsv formula acquired from: https://www.rapidtables.com/convert/color/rgb-to-hsv.html

  double max = std::max({r, g, b});
  double min = std::min({r, g, b}); 
  double delta = max - min;

  // hue calculation
  if (delta == 0){
    h = 0;
  } else if (max == r){
    h = 60 * (g - b) / delta;
  } else if (max == g){
    h = 60 * (((b - r) / delta) + 2);
  } else {
    h = 60 * (((r - g) / delta) + 4);
  }

  // adjust hue angle
  if (h < 0){
    h += 360;
  } else if (h >= 360){
    h -= 360;
  }

  // saturation calculation
  if (max == 0){
    s = 0;
  } else {
    s = delta / max;
  }

  // value calculation
  v = std::max({r, g, b});
}
