#ifndef __BRDF_H__
#define __BRDF_H__
#include "Samplers/Sampler.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
#include "Utilities/Vector3D.h"
class BRDF
{
   /**
    * Construct a new BRDF
    * Default sampler is Multijittered wiht 16 samples
    */
   BRDF();

   BRDF(Sampler * sampler_ptr);

   BRDF(const BRDF & other);

   virtual BRDF*
      clone(void) const = 0;

   ~BRDF(void);

   virtual RGBColor f(const ShadeRec  &sr, const Vector3D & wi, const Vector3D & wo) const = 0;

   virtual RGBColor sample_f(const ShadeRec & sr, const Vector3D & wi, const Vector3D & wo) const = 0;

   /**
    * Bihemispherical reflectance (ambient)
    * @return [description]
    */
   virtual RGBColor rho(const ShadeRec& sr, const Vector3D & wo) const = 0;

   void set_sampler(Sampler * sampler_ptr);

protected:
   Sampler * sampler_ptr;
};
#endif