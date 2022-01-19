#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);

  // populate bayer vector using following layout:
  // GBGB
  // RGRG
  int pos = 0;
  for (int j = 0; j < height; j++){
    for (int i = 0; i < width, pos < bayer.size(); i++){
      // GBGB
      bayer[pos] = rgb[1 + i%2 + 3 * (i + j * width)];
      pos++;
    }
    j+=1;
    for (int i = 0; i < width, pos < bayer.size(); i++){
      // RGRG
      bayer[pos] = rgb[i%2 + 3 * (i + j * width)];
      pos++;
    }
  }
}
