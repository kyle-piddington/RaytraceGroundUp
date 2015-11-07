#include "Samplers/Jittered.h"
#include "Utilities/Maths.h"
#include <math.h>
Jittered::Jittered(int num_samples):
   Sampler(num_samples)
{

}

Jittered::~Jittered()
{

}

void Jittered::generate_samples()
{
   int n = (int) sqrt(num_samples);

   for(int p = 0; p < num_sets; p++)
   {
      for(int j = 0; j < n; j++)
      {
         for(int k = 0; k < n; k++)
         {
            Point2D sp((k + rand_float())/ n, (j + rand_float()) / n);
            samples.push_back(sp);
         }
      }
   }
}