#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);

  // populate new vector accordingly
  int pos = 0;
  for (int j = 0; j < height; j++){
    // horizontal reflection means row arrays are reversed
    for (int i = width - 1; i >= 0; i--){
      reflected[pos] = input[3 * (i + j * width)];
      reflected[pos + 1] = input[1 + 3 * (i + j * width)];
      reflected[pos + 2] = input[2 + 3 * (i + j * width)];
      pos += 3;
    }
  }
}