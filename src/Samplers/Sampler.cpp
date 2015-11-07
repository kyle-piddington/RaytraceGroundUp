#include "Samplers/Sampler.h"
#include "Utilities/Maths.h"
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
   return(samples[count++ % (num_samples * num_sets)]);
}

int Sampler::get_num_samples() const
{
   return num_samples;
}


