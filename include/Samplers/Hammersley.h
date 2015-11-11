#ifndef __HAMMERSLEY_SAMPLER_H__
#define __HAMMERSLEY_SAMPLER_H__
#include "Samplers/Sampler.h"
class Hammersley : public Sampler
{
public:
   Hammersley(int num_samples);
   ~Hammersley();
private:
   virtual void generate_samples();
};
#endif