#include "Materials/Matte.h"
#include "World/World.h"
Matte::Matte() :
   Material(),
   ambient_brdf(new Lambertian),
   diffuse_brdf(new Lambertian)
   {

   }
Matte::Matte(const Matte & rhs):
   Material(),
   ambient_brdf(rhs.ambient_brdf->clone()),
   diffuse_brdf(rhs.diffuse_brdf->clone())
{

}
Matte::~Matte()
{
   if(ambient_brdf)
      delete ambient_brdf;
   if(diffuse_brdf)
      delete diffuse_brdf;
}
Matte & Matte::operator=(const Matte& other)
{
   if(&other == this)
   {
      return *this;
   }
   if(ambient_brdf)
      delete ambient_brdf;
   this->ambient_brdf = other.ambient_brdf;
   if(diffuse_brdf)
      delete diffuse_brdf;
   this->diffuse_brdf = other.diffuse_brdf;

   return *this;
}

void Matte::set_ka(const float k)
{
   ambient_brdf->set_kd(k);
}
void Matte::set_kd(const float kd)
{
   diffuse_brdf->set_kd(kd);
}

void Matte::set_cd(const RGBColor & c)
{
   ambient_brdf->set_cd(c);
   diffuse_brdf->set_cd(c);
}
Matte * Matte::clone() const
{
   return new Matte(*this);
}

RGBColor Matte::shade(ShadeRec & sr)
{
   Vector3D wo = -sr.ray.d;
   //Calculate Ambient Light
   RGBColor L = ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);
   int numLights = sr.w.lights.size();

   for(int j = 0; j < numLights; j++)
   {
      Vector3D wi = sr.w.lights[j]->get_direction(sr);
      float ndotwi = sr.normal * wi;
      if(ndotwi > 0.0f)
      {
         L += diffuse_brdf->f(sr,wo,wi) * sr.w.lights[j]->L(sr) * ndotwi;
      }

   }
   return L;

}
