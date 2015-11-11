#include "Samplers/Hammersley.h"

/**
 * Calculate the binary fraction of j
 * @param  j the input function
 * @return   the binary fraction (ie calcPhi(0xb100) = 0xb0.001 = 1/8)
 */
float calcPhi(int j)
{
   double x = 0.0;
   double f = 0.5;

   while (j) {
      x += f * (double) (j % 2);
      j /= 2;
      f *= 0.5;
   }

   return (x);
}
Hammersley::Hammersley(int num_samples):
   Sampler(num_samples,1)
{

}
Hammersley::~Hammersley()
{

}

void Hammersley::generate_samples()
{
   float xWdth = 1.0f/num_samples;
   for(int i = 0; i < num_samples; i++)
   {
      Point2D pt(i * xWdth, calcPhi(i));
      samples.push_back(pt);
   }
}