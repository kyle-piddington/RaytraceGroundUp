#include "Samplers/MultiJittered.h"
#include "Utilities/Maths.h"
#include <math.h>
#include <random>
MultiJittered::MultiJittered(int num_samples):
Sampler(num_samples)
{

}

MultiJittered::MultiJittered(const MultiJittered & other):
Sampler(other)
{

}

MultiJittered * MultiJittered::clone() const
{
   return new MultiJittered(*this);
}

MultiJittered::~MultiJittered()
{

}

void MultiJittered::generate_samples()
{
   int n = (int)sqrt((float)num_samples);
   float subcell_width = 1.0 / ((float) num_samples);
   
   
   //Set up initial diagonal sets   
   for(int p = 0; p < num_sets; p++)
   {
      for(int j = 0; j < n; j++)
      {
         for(int k = 0; k < n; k++)
         {
            Point2D sp;
            sp.x = (j * n + k) * subcell_width + rand_float()*subcell_width;  //set the X to j'th cell, k'th subcell
            sp.y = (k * n + j) * subcell_width + rand_float()*subcell_width;  //Set the Y to k'th cell, j'th subcell
            samples.push_back(sp);
         }
      }
   }
   shuffle_x_coordinates();
   shuffle_y_coordinates();
}

void MultiJittered::shuffle_x_coordinates()
{
   for(int p = 0; p < num_sets; p++)
   {
      for(int i = 0; i < num_samples - 1; i++)
      {
         int target = rand() % num_samples + p * num_samples; //select a random cell
         float tempX = samples[i + p*num_samples + 1].x;
         samples[i + p * num_samples + 1].x = samples[target].x;
         samples[target].x = tempX;
      }
   }
}
void MultiJittered::shuffle_y_coordinates()
{
   for(int p = 0; p < num_sets; p++)
   {
      for(int i = 0; i < num_samples - 1; i++)
      {
         int target = rand() % num_samples + p * num_samples; //select a random cell
         float tempY = samples[i + p*num_samples + 1].y;
         samples[i + p * num_samples + 1].y = samples[target].y;
         samples[target].y = tempY;
      }
   }
}
