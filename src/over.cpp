#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());

  // Porter-Duff over formula acquired from: https://en.wikipedia.org/wiki/Alpha_compositing

  double alpha_A, alpha_B, alpha_C;

  int pos = 0;
  for (int j = 0; j < height; j++){
    for (int i = 0; i < width; i++){
      // calculate alphas of A and B pixels
      alpha_A = ((double) A[3 + 4 * (i + j * width)]) / 255.0;
      alpha_B = ((double) B[3 + 4 * (i + j * width)]) / 255.0;

      alpha_C = alpha_A + alpha_B * (1 - alpha_A);

      // calculate the rgba values for the composite pixel
      C[pos] = ( (double) A[0 + 4 * (i + j * width)] * alpha_A + (double) B[0 + 4 * (i + j * width)] * alpha_B * (1 - alpha_A) ) / (alpha_C);
      C[pos + 1] = ( (double) A[1 + 4 * (i + j * width)] * alpha_A + (double) B[1 + 4 * (i + j * width)] * alpha_B * (1 - alpha_A) ) / (alpha_C);
      C[pos + 2] = ( (double) A[2 + 4 * (i + j * width)] * alpha_A + (double) B[2 + 4 * (i + j * width)] * alpha_B * (1 - alpha_A) ) / (alpha_C);
      C[pos + 3] = alpha_C * 255.0;
      pos += 4;
    }
  }
}
