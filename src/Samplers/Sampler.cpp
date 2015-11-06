#include "Sampler/Sampler.cpp"

Sampler::Sampler(int num_samples, int num_sets) :
   num_samples(num_samples),
   num_set(num_sets)
   {
      generate_samples();
   }
