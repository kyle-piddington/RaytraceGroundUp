#include "Lights/Light.h"

Light::Light(void):
   shadows(false)
{

}
Light::Light(const Light & ls):
   shadows(ls.shadows)
{

}
Light::~Light()
{
   
}
Light& Light::operator = (const Light & rhs)
{
   this->shadows = rhs.shadows;
   return *this;
}

void Light::set_shadows(bool shadows)
{
   this->shadows = shadows;
}

bool Light::get_shadows() const
{
   return this->shadows;
}

