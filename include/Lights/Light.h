#ifndef __LIGHT_H__
#define __LIGHT_H__
#include "Utilities/RGBColor.h"
#include "Utilities/Vector3D.h"
#include "Utilities/ShadeRec.h"

class Light
{
public:
   /**
    * Create a light
    */
   Light(void);
   /**
    * Copy a light
    */
   Light(const Light& ls);

   virtual ~Light();
   /**
    * Copy constructor
    */
   Light&
   operator= (const Light& rhs);

   void set_shadows(bool shadows);

   bool get_shadows() const;
   /**
    * Clone the light
    * @return  a new light
    */
   virtual Light* clone(void) const = 0;


   virtual Vector3D get_direction(ShadeRec & sr) const = 0;
   virtual RGBColor L(const ShadeRec & sr) const = 0;

protected:
   bool shadows;
};
#endif