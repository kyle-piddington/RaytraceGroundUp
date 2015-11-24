#ifndef __AMBIENT_H__
#define __AMBIENT_H__
#include "Lights/Light.h"
class Ambient : public Light
{
public:
   Ambient(void);

   Ambient(const Ambient& a);

   virtual Light*
   clone(void) const;

   Ambient&
   operator= (const Ambient& rhs);

   virtual
   ~Ambient(void);

   void
   scale_radiance(const float b);

   void
   set_color(const float c);

   void
   set_color(const RGBColor& c);

   void
   set_color(const float r, const float g, const float b);

   Vector3D get_direction(ShadeRec & sr);

   RGBColor L(ShadeRec & sr);
private:
   float ls;
   RGBColor color;

};
#endif