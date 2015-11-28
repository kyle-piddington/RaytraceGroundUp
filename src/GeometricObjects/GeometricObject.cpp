#include "GeometricObjects/GeometricObject.h"
#include "Utilities/Constants.h"
#include "Materials/Material.h"
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
   if(material)
      delete material;
}

GeometricObject & GeometricObject::operator= (const GeometricObject& rhs)
{
   if(this == &rhs)
   {
      return *this;
   }
   this->color = rhs.color;
   if(material)
      delete material;
   this->material = rhs.material->clone();
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

Material * GeometricObject::get_material()
{
   return material;
}

void GeometricObject::set_material(Material * material)
{
   if(this->material)
      delete this->material;
   this->material = material->clone();
}