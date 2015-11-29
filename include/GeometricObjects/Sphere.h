#ifndef __SPHERE_H__
#define __SPHERE_H__
#include "GeometricObjects/GeometricObject.h"
class Sphere : public GeometricObject
{
public:

   Sphere(void);

   Sphere(Point3D center, double r);

   Sphere(const Sphere & sphere);

   virtual Sphere * clone(void) const;

   virtual ~Sphere(void);

   virtual Sphere & operator= (const Sphere & sphere);


   void set_center(const Point3D & c);
   
   void set_center(const double x, const double y, const double z);

   void set_radius(const double r);

   virtual bool hit(const Ray & ray, double & tmin, ShadeRec & sr) const;

private:
   Point3D center;
   double radius;

   static const double kEpsilon;
};
#endif