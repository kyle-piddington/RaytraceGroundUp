#ifndef __MATERIAL_H__
#define __MATERIAL_H__
#include "Utilities/ShadeRec.h"
class Material
{
public:

   virtual ~Material();
   virtual Material * clone() const = 0;
   virtual RGBColor shade(ShadeRec & sr);
   virtual RGBColor area_light_shade(ShadeRec & sr);
   virtual RGBColor path_shade(ShadeRec & sr);
};
#endif