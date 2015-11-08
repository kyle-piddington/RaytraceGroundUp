#ifndef __REGULAR_SAMPLER_H__
#define __REGULAR_SAMPLER_H__
#include "Samplers/Sampler.h"
class Regular : public Sampler
{
public:
   Regular(int num_samples);
   ~Regular();
private:
   virtual void generate_samples();
};
#endif