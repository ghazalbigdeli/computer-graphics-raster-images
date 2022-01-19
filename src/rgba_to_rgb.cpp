#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);

  // loop through rgba while filling up rgb appropriately
  for (int i = 0, j = 0; i < rgba.size() - 3, j < rgb.size() - 2; i+=4, j+=3){
    rgb[j] = rgba[i];
    rgb[j + 1] = rgba[i + 1];
    rgb[j + 2] = rgba[i + 2];
  }
}
