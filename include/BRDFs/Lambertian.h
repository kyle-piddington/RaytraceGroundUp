#ifndef __LAMBERTIAN_H__
#define __LAMBERTIAN_H__
#include "BRDFs/BRDF.h"
class Lambertian : public BRDF
{
public:
   Lambertian();

   Lambertian(Sampler * sampler_ptr, float kd, const RGBColor & cd);

   Lambertian(const Lambertian & other);

   virtual ~Lambertian();

   
   virtual Lambertian * clone() const;

   Lambertian & operator=(const Lambertian & rhs);

   void set_kd(float kd);

   void set_cd(const RGBColor & c);

    virtual RGBColor f(const ShadeRec  &sr, const Vector3D & wi, const Vector3D & wo) const;

   virtual RGBColor sample_f(const ShadeRec & sr, const Vector3D & wi, const Vector3D & wo) const;

   /**
    * Bihemispherical reflectance (ambient)
    * @return [description]
    */
   virtual RGBColor rho(const ShadeRec& sr, const Vector3D & wo) const;

private:
   float kd;
   RGBColor cd;
};
#endif