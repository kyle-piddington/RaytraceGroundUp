#ifndef __GEMOETRIC_OBJECT_H_
#define __GEMOETRIC_OBJECT_H_
#include "Utilities/Ray.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
/**
 * Interface for any objects in the raytracer
 */

class GeometricObject
{
public:
   GeometricObject();

   GeometricObject(const GeometricObject & object);

   virtual GeometricObject * clone(void) const = 0;


   virtual ~GeometricObject();

   virtual bool hit(const Ray& ray, double & tmin, ShadeRec & sr) const = 0;

   void set_color(const RGBColor & color);

protected:
   RGBColor color; //Will be replaced with a material later.

   GeometricObject & operator= (const GeometricObject & rhs);
};
#endif