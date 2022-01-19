#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);

  // populate new vector accordingly
  int pos = 0;
  // to rotate 90 counter clockwise, compute last column as first row and onwards
  for (int i = width - 1; i >= 0; i--){
    for (int j = 0; j < height; j++){
      rotated[pos] = input[3 * (i + j * width)];
      rotated[pos + 1] = input[1 + 3 * (i + j * width)];
      rotated[pos + 2] = input[2 + 3 * (i + j * width)];
      pos += 3;
    }
  }
}