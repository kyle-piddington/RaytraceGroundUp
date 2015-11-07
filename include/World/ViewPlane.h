#ifndef __ViewPlane_H__
#define __ViewPlane_H__
#include "Samplers/Sampler.h"
class ViewPlane {
public:
   ViewPlane();
   ~ViewPlane();
   int hRes; //Horizontal image resolution
   void set_hRes(int hRes);

   int vRes; //Vertical image resolution
   void set_vRes(int vRes);

   float s; //Pixel size
   void set_pixel_size(float pxSize);

   //Set the sampler
   void set_sampler(Sampler * sp);

   //Set the number of samples in a sampler.
   //By default, use MultiJittered rendering for n > 1 samples
   //or Regular sampling for n = 1 samples
   void set_samples(const int n);

   float gamma; //Monitor gamma factor;
   float inv_gamma; // One over gamma;
   void set_gamma(float gamma);

   int get_num_samples() const;
   Sampler * get_sampler_ptr() const;

private:
   Sampler * sampler_ptr;
   int num_samples;


};
#endif