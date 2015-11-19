#include "BRDFs/BRDF.h"
#include "Samplers/MultiJittered.h"
BRDF::BRDF():
   sampler_ptr(new MultiJittered(16))
{

}
BRDF::BRDF(Sampler * sampler_ptr):
   sampler_ptr(sampler_ptr->clone())
{

}

BRDF::BRDF(const BRDF & other):
   sampler_ptr(other.sampler_ptr->clone())
{
   
}

BRDF::~BRDF()
{
   if(sampler_ptr)
   {
      delete sampler_ptr;
   }
}
BRDF&  BRDF::operator= (const BRDF& rhs)
{
   if(&rhs == this)
      return *this;
   if(sampler_ptr)
      delete sampler_ptr;
   this->sampler_ptr = rhs.sampler_ptr->clone();

   return *this;
}


void BRDF::set_sampler(Sampler * sampler_ptr)
{
   if(this->sampler_ptr)
   {
      delete this->sampler_ptr;
   }
   this->sampler_ptr = sampler_ptr;
}


