#include "rgb_to_gray.h"

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);

  // populate gray vector accordingly
  unsigned char r, g, b;
  int pos = 0;
  for (int x = 0; x < rgb.size() - 3; x += 3){
    r = rgb[x];
    g = rgb[x + 1];
    b = rgb[x + 2];

    // formula acquired from tutorial slides
    gray[pos] = 0.212 * r + 0.7152 * g +  0.0722 * b;
    pos++;
  }
}


