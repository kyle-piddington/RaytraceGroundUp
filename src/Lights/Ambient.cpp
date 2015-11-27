#include "Lights/Ambient.h"
#include "Utilities/Constants.h"

Ambient::Ambient():
   ls(1.0),
   color(1.0)
{

}

Ambient::Ambient(const Ambient & a):
   Light(a),
   ls(a.ls),
   color(a.color)
{

}

Light * Ambient::clone(void) const
{
   return new Ambient(*this);
}

Ambient& Ambient::operator= (const Ambient& rhs)
{
   this->ls = rhs.ls;
   this->color = rhs.color;
   this->shadows = rhs.shadows;
   return *this;
}

Ambient::~Ambient()
{

}

void Ambient::scale_radiance(const float b)
{
   ls = b;
}

void Ambient::set_color(const float c)
{
   this->color = RGBColor(c);
}

void Ambient::set_color(const RGBColor& c)
{
   this->color = RGBColor(c);
}

void Ambient::set_color(const float r, const float g, const float b)
{
   this->color = RGBColor(r,g,b);
}

Vector3D Ambient::get_direction(ShadeRec & sr) const
{
   return Vector3D(0.0);
}
RGBColor Ambient::L(const ShadeRec & sr) const{
   return ls * color;
}

