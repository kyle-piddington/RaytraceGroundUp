#ifndef __GEMOETRIC_OBJECT_H_
#define __GEMOETRIC_OBJECT_H_
#include "Utilities/Ray.h"
#include "Utilities/RGBColor.h"
#include "Utilities/ShadeRec.h"
/**
 * Interface for any objects in the raytracer
 */
class Material;
class GeometricObject
{
public:
   GeometricObject();

   GeometricObject(const GeometricObject & object);


   virtual ~GeometricObject();

   virtual bool hit(const Ray& ray, double & tmin, ShadeRec & sr) const = 0;

   void set_color(const RGBColor & color);

   void set_color(float r, float g, float b);

   RGBColor get_color() const;

   Material * get_material();

   void set_material(Material * material);


protected:
   RGBColor color; //Will be replaced with a material later.
   Material * material;
   virtual GeometricObject & operator= (const GeometricObject & rhs);
};
#endif