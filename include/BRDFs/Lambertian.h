#ifndef __LAMBERTIAN_H__
#define __LAMBERTIAN_H__
#include "BRDFs/BRDF.h"
class Lambertian : public BRDF
{
   Lambertian();

   Lambertian(Sampler * sampler_ptr);

   Lambertian(const Lambertian & other);

   virtual BRDF * clone() const;

   ~Lambertian();

    virtual RGBColor f(const ShadeRec  &sr, const Vector3D & wi, const Vector3D & wo) const;

   virtual RGBColor sample_f(const ShadeRec & sr, const Vector3D & wi, const Vector3D & wo) const;

   /**
    * Bihemispherical reflectance (ambient)
    * @return [description]
    */
   virtual RGBColor rho(const ShadeRec& sr, const Vector3D & wo);

virtual RGBCo

};
#endif