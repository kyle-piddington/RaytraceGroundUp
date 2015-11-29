#include "Lights/PointLight.h"

PointLight::PointLight():

   ls(1.0),
   color(1.0),
   location(0.0)
{

}
PointLight::PointLight(const PointLight & other):
   Light(other),
   ls(other.ls),
   color(other.color),
   location(other.location)
{

}

PointLight * PointLight::clone() const
{
   return new PointLight(*this);
}

PointLight & PointLight::operator=(const PointLight & other)
{

   this->ls = other.ls;
   this->color = other.color;
   this->location = other.location;
   this->shadows = other.shadows;
   return *this;
}

Vector3D PointLight::get_direction(ShadeRec & sr) const
{
   return (location - sr.hit_point).hat();
}


RGBColor PointLight::L(const ShadeRec & sr) const
{
   return ls * color;
}

void PointLight::set_location(const Vector3D & loc)
{
   this->location = loc;
}

void PointLight::set_location(const float x, const float y, const float z)
{
   this->location = Vector3D(x,y,z);
}

void PointLight::set_location(const float a)
{
   this->location = Vector3D(a);
}

void PointLight::scale_radiance(const float b)
{
   this->ls = b;
}

void PointLight::set_color(const float c)
{
   this->color = RGBColor(c);
}

void PointLight::set_color(const RGBColor & c)
{
   this->color = c;
}
