#include "GeometricObjects/Sphere.h"
#include <math.h>
#include <iostream>
const double Sphere::kEpsilon =  0.001;
Sphere::Sphere(void):
   GeometricObject()
{

}

Sphere::Sphere(Point3D center, double r):
   GeometricObject(),
   center(center),
   radius(r)
{

}
Sphere::Sphere(const Sphere & sphere) :
   GeometricObject(sphere),
   center(sphere.center),
   radius(sphere.radius)
{

}

Sphere::~Sphere()
{

}

Sphere * Sphere::clone(void) const
{
   return new Sphere(*this);
}

void Sphere::set_center(const Point3D & c)
{
   this->center = c;
}

void Sphere::set_center(const double x, const double y, const double z)
{
   this->center = Point3D(x,y,z);
}

void Sphere::set_radius(const double r)
{
   this->radius = r;
}

bool Sphere::hit(const Ray & ray, double & tmin, ShadeRec& sr) const
{
   double t;
   Vector3D temp = ray.o - center;
   double a = ray.d * ray.d; //Dot product
   double b = 2.0 * temp * ray.d;
   double c = temp*temp - radius * radius;
   double disc = b*b - 4.0 * a * c; //Discriminant of a Quadradic Equation

   if(disc < 0.0)
   {
      return false;
   }
   else
   {
      double e = sqrt(disc);
      double denom = 2.0 * a;
      t = (-b - e) / denom;
      if(t > kEpsilon)
      {
         tmin = t;
         sr.normal = (temp + t * ray.d) / radius;
         sr.local_hit_point = ray.o + t * ray.d;
         return true;
      }
   }
   return false;
}
Sphere & Sphere::operator= (const Sphere & rhs)
{
   if(&rhs == this)
      return *this;
   GeometricObject::operator= (rhs);

   center 	= rhs.center;
   radius	= rhs.radius;

   return (*this);

}
