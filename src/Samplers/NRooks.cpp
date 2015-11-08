#include "Samplers/NRooks.h"
#include "Utilities/Maths.h"
#include <math.h>
#include <random>
NRooks::NRooks(int num_samples):
Sampler(num_samples)
{

}

NRooks::~NRooks()
{

}

void NRooks::generate_samples()
{

   //Set up initial diagonal sets   
   for(int p = 0; p < num_sets; p++)
   {
      for(int j = 0; j < num_samples; j++)
      {
         Point2D pv;
         pv.x = (j+rand_float()) / num_samples;
         pv.y = (j+rand_float()) / num_samples;
         samples.push_back(pv);
         
      }
   }
   shuffle_x_coordinates();
   shuffle_y_coordinates();
}

void NRooks::shuffle_x_coordinates()
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
void NRooks::shuffle_y_coordinates()
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
