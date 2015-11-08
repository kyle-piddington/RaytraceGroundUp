#include "Samplers/Regular.h"
#include <math.h>
Regular::Regular(int num_samples):
   Sampler(num_samples,1)
{

}

Regular::~Regular()
{

}

void Regular::generate_samples()
{
   int n = (int) sqrt(num_samples);

   for(int p = 0; p < num_sets; p++)
   {
      for(int j = 0; j < n; j++)
      {
         for(int k = 0; k < n; k++)
         {
            Point2D sp(k / n, j  / n);
            samples.push_back(sp);
         }
      }
   }
}