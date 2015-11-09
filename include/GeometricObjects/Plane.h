#ifndef __PLANE_H__
#define __PLANE_H__
#include "Utilities/Point3D.h"
#include "Utilities/Normal.h"
#include "Utilities/ShadeRec.h"
#include "GeometricObjects/GeometricObject.h"

class Plane : public GeometricObject
{
public:
   Plane(void);

   Plane(Point3D point, Normal normal);

   Plane(const Plane & Plane);

   virtual Plane * clone(void) const;

   virtual ~Plane(void);

   Plane & operator= (const Plane & Plane);

   void set_point(const Point3D & c);
   
   void set_point(const double x, const double y, const double z);
   
   void set_normal(const Normal & c);
   
   void set_normal(const double x, const double y, const double z);

   virtual bool hit(const Ray & ray, double & tmin, ShadeRec & sr) const;

private:
   Point3D point;
   Normal normal;
   const static double kEpsilon;
};
#endif