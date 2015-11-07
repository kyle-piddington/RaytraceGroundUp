#include "World/ViewPlane.h"
#include <iostream>
ViewPlane::ViewPlane() :
sampler_ptr(nullptr)
{

}
ViewPlane::~ViewPlane()
{
   if(sampler_ptr != nullptr)
   {
      delete sampler_ptr;
      sampler_ptr = nullptr;
   }
}
void ViewPlane::set_hRes(int hRes)
{
   this->hRes = hRes;
}

void ViewPlane::set_vRes(int vRes)
{
   this->vRes = vRes;
}

void ViewPlane::set_pixel_size(float pxSize)
{
   this->s = pxSize;
}
void ViewPlane::set_gamma(float gamma)
{
   this->gamma = gamma;
   this->inv_gamma = 1.0/gamma;
}

int ViewPlane::get_num_samples() const
{
   return sampler_ptr->get_num_samples();
}

void ViewPlane::set_sampler(Sampler * sp)
{
   if(sampler_ptr != nullptr)
   {
      delete sampler_ptr;
      sampler_ptr = nullptr;
   }
   num_samples = sp->get_num_samples();
   sampler_ptr = sp;
}

Sampler * ViewPlane::get_sampler_ptr() const
{
   return sampler_ptr;
}