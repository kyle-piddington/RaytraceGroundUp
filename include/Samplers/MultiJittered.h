#ifndef __MULTIJITTERED_SAMPLER_H__
#define __MULTIJITTERED_SAMPLER_H__
#include "Samplers/Sampler.h"
class MultiJittered : public Sampler
{
public:
   MultiJittered(int num_samples);
   ~MultiJittered();
private:
   virtual void generate_samples();
   void shuffle_x_coordinates();
   void shuffle_y_coordinates();
};
#endif