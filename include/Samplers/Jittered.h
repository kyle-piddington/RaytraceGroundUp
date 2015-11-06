#ifndef __JITTERED_SAMPLER_H__
#define __JITTERED_SAMPLER_H__
#include "Samplers/Sampler.h"
class Jittered : public Sampler
{
public:
   Jittered(int num_samples);
   ~Jittered();
private:
   virtual void generate_samples();
};
#endif