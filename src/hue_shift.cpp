#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  
  double h, s, v;
  double r, g, b, c, m;

  int pos = 0;
  for (int j = 0; j < height; j++){
    for (int i = 0; i < width; i++){
      r = (double) rgb[3 * (i + j * width)];
      g = (double) rgb[1 + 3 * (i + j * width)];
      b = (double) rgb[2 + 3 * (i + j * width)];

      // convert rgb to hsv
      rgb_to_hsv(r/255.0, g/255.0, b/255.0, h, s, v);

      // shift the hue using the provided value
      h = h + shift;
      if (h >= 360){
        h -= 360;
      }

      // convert back to rgb
      hsv_to_rgb(h, s, v, r, g, b);

      // populate final shifted vector with rgb values
      c = v * s;
      m = v - c;
      shifted[pos] = (unsigned char) round ((r + m) * 255.0);
      shifted[pos + 1] = (unsigned char) round ((g + m) * 255.0);
      shifted[pos + 2] = (unsigned char) round ((b + m) * 255.0);
      pos += 3;
    }
  }
}
