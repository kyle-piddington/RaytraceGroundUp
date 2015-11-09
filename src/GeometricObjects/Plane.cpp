#include "GeometricObjects/Plane.h"
#include <math.h>
#include <iostream>
const double Plane::kEpsilon =  0.001;
Plane::Plane(void):
   GeometricObject(),
   point(0,0,0),
   normal(0,1,0)
{

}

Plane::Plane(Point3D point, Normal normal):
   GeometricObject(),
   point(point),
   normal(normal)
{

}
Plane::Plane(const Plane & Plane) :
   GeometricObject(Plane),
   point(Plane.point),
   normal(Plane.normal)
{

}  

Plane::~Plane()
{

}

Plane * Plane::clone(void) const
{
   return new Plane(*this);
}

void Plane::set_point(const Point3D & p)
{
   this->point = p;
}

void Plane::set_point(const double x, const double y, const double z)
{
   this->point = Point3D(x,y,z);
}

void Plane::set_normal(const Normal & n)
{
   this->normal = n;
}

void Plane::set_normal(const double x, const double y, const double z)
{
   this->normal = Normal(x,y,z);
}


bool Plane::hit(const Ray & ray, double & tmin, ShadeRec& sr) const
{
   double t = (point - ray.o) * normal / (ray.d * normal);
   if (t > kEpsilon){
      tmin = t;
      sr.normal = normal;
      sr.local_hit_point = ray.o + t * ray.d;
      return true;
   }
   else
   {
      return false;
   }
}