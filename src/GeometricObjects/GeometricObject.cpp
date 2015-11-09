#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Constants.h"
GeometricObject::GeometricObject(void) :
   color(black)
   {

   }
GeometricObject::GeometricObject(const GeometricObject & object)
{
   this->color = object.color;
}

GeometricObject::~GeometricObject()
{

}

GeometricObject & GeometricObject::operator= (const GeometricObject& rhs)
{
   if(this == &rhs)
   {
      return *this;
   }
   this->color = rhs.color;
   return *this;
}



void GeometricObject::set_color(const RGBColor & color)
{
   this->color = color;
}

void GeometricObject::set_color(float r, float g, float b)
{
   this->color = RGBColor(r,g,b);
}

RGBColor GeometricObject::get_color() const
{
   return color;
}