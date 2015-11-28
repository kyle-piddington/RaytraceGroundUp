#include "BRDFs/Lambertian.h"
#include "Samplers/Multijittered.h"
#include "Utilities/Constants.h"
Lambertian::Lambertian():
   BRDF(new MultiJittered(16)),
   kd(0.0),
   cd(black)
{

}
Lambertian::Lambertian(Sampler * sampler_ptr, float kd, const RGBColor & cd):
   BRDF(sampler_ptr),
   kd(kd),
   cd(cd)
{
 
}

Lambertian::Lambertian(const Lambertian & other):
   BRDF(other),
   kd(other.kd),
   cd(other.cd)
{

}

Lambertian::~Lambertian()
{

}
Lambertian * Lambertian::clone() const
{

   return new Lambertian(*this);
}

Lambertian & Lambertian::operator=(const Lambertian & rhs)
{

   if(&rhs == this)
      return *this;
   if(sampler_ptr)
      delete sampler_ptr;
   if(this->sampler_ptr)
      delete sampler_ptr;
   this->sampler_ptr = rhs.sampler_ptr->clone();
   this->kd = rhs.kd;
   this->cd = rhs.cd;
   return *this;
}

void Lambertian::set_kd(float k)
{
   this->kd = k;
}
void Lambertian::set_cd(const RGBColor & cd)
{
   this->cd =cd;
}
//Light scatters evenly for all input and output angles
RGBColor Lambertian::f(const ShadeRec & sr, const Vector3D & wi, const Vector3D & wo) const
{
   return kd * cd * invPI;
}

RGBColor Lambertian::rho(const ShadeRec & sr, const Vector3D& wo) const {
   return kd * cd;
}

//@TODO complete this function in Chapter 26
RGBColor Lambertian::sample_f(const ShadeRec & sr, const Vector3D & wi, const Vector3D & w) const
{
   return black;
}