#ifndef __NROOKS_SAMPLER_H__
#define __NROOKS_SAMPLER_H__
#include "Samplers/Sampler.h"
class NRooks : public Sampler
{
public:
   NRooks(int num_samples);
   ~NRooks();
private:
   virtual void generate_samples();
   void shuffle_x_coordinates();
   void shuffle_y_coordinates();
    
};
#endif