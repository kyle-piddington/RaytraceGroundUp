#ifndef __MATTE_H__
#define __MATTE_H__
#include "BRDFs/Lambertian.h"
#include "Materials/Material.h"
class Matte : public Material
{
public:
   Matte();
   Matte(const Matte & rhs);
   virtual ~Matte();
   Matte * clone() const;
   Matte & operator= (const Matte & other);

   void set_ka(const float k);
   void set_kd(const float k);
   void set_cd(const RGBColor & c);
   virtual RGBColor shade(ShadeRec & sr);

private:
   Lambertian * ambient_brdf;
   Lambertian * diffuse_brdf;
};
#endif