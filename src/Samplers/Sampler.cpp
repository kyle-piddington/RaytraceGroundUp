#include "Samplers/Sampler.h"
#include "Utilities/Maths.h"
#include <random>
#include <iostream>
Sampler::Sampler(int num_samples, int num_sets) :
   num_samples(num_samples),
   num_sets(num_sets),
   initializedSamples(false)
{

}
Sampler::Sampler(const Sampler & other):
   num_samples(other.num_samples),
   num_sets(other.num_sets),
   samples(other.samples),
   shuffled_indices(other.shuffled_indices),
   count(other.count),
   jump(other.jump),
   initializedSamples(other.initializedSamples)
{

}



Sampler::~Sampler()
{
  
}

void Sampler::setup_shuffled_indices()
{
   shuffled_indices.reserve(num_samples*num_sets);
   std::vector<int> indicies;
   for(int j = 0; j < num_samples; j++)
   {
      indicies.push_back(j);
   }
   for(int p = 0; p < num_sets; p++)
   {
      random_shuffle(indicies.begin(),indicies.end());
      for(int j = 0; j < num_samples; j++)
      {
         shuffled_indices.push_back(indicies[j]);
      }
   }

}
Point2D Sampler::sample_unit_square()
{
   if(!initializedSamples)
   {
      samples.reserve(num_samples*num_sets);

      setup_shuffled_indices();
      generate_samples();
      
      initializedSamples = true;
   }
   if(count % num_samples == 0)
   {
      jump = (rand() % num_sets) * num_samples;
   }
   return(samples[jump + shuffled_indices[jump + count++ % num_samples]]);
}

int Sampler::get_num_samples() const
{
   return num_samples;
}


