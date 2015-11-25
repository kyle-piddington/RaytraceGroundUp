#ifndef __POINT_LIGHT_H__
#define __POINT_LIGHT_H__
#include "Utilities/Vector3D.h"
#include "Lights/Light.h"
class PointLight : public Light
{
public:
   PointLight();

   PointLight(const PointLight & other);

   virtual Light * clone(void) const;

   PointLight & operator=(const PointLight & other);

   virtual Vector3D get_direction(ShadeRec & sr);

   virtual RGBColor L(ShadeRec & sr);

   void set_location(const Vector3D & loc);

   void set_location(const float x, const float y, const float z);


   void scale_radiance(const float b);

   void set_color(const float c);

   void set_color(const RGBColor & c);




private:
   float ls;
   RGBColor color;
   Vector3D location;



};
#endif