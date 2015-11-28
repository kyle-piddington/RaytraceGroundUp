#include "Materials/Material.h"
#include "Utilities/Constants.h"
Material::~Material()
{
   
}
RGBColor Material::shade(ShadeRec & sr)
{
   return black;
}
RGBColor Material::area_light_shade(ShadeRec & sr)
{
   return black;
}
RGBColor Material::path_shade(ShadeRec & sr)
{
   return black;
}