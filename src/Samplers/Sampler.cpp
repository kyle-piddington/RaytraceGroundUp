#include "Samplers/Sampler.h"
#include "Utilities/Maths.h"
#include <random>
Sampler::Sampler(int num_samples, int num_sets) :
   num_samples(num_samples),
   num_sets(num_sets)
{
}

Sampler::~Sampler()
{

}

Point2D Sampler::sample_unit_square()
{
   if(!initializedSamples)
   {
      generate_samples();
      initializedSamples = true;
   }
   if(count % num_samples == 0)
   {
      jump = (rand() % num_sets) * num_samples;
   }
   return(samples[jump + count++ % (num_samples * num_sets)]);
}

int Sampler::get_num_samples() const
{
   return num_samples;
}


