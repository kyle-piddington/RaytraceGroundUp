#include "Utilities/Constants.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Point3d.h"
#include "Utilities/Normal.h"
#include "Utilities/Ray.h"
#include "UserInterface/RenderInterface.h"
#include "World/World.h"
#include "stb/stb_image_write.h"

#include <iostream>


#include "Build/BuildMultipleObjects.cpp"


World::World()
{
   
}


void World::display_pixel(const int row,  const int col,const RGBColor & color) const
{
      
   
   paintArea->set_pixel(row,col,color.r * 255,color.g * 255,color.b * 255);
}

void World::open_window(const int vRes, const int hRes) const
{
   paintArea->prepare(vRes, hRes);
}

inline void World::add_object(GeometricObject * obj)
{
   objects.push_back(obj);
}

ShadeRec World::hit_bare_bones_objects(const Ray & ray) const
{
   ShadeRec sr (*this);
   double t;
   double tmin = kHugeValue;
   int num_objects = objects.size();
   for(int i = 0; i < num_objects; i++)
   {
      if(objects[i]->hit(ray,t,sr) && t < tmin)
      {
         sr.hit_an_object = true;
         tmin = t;
         sr.color = objects[i]->get_color();
      }
   }
   return sr;
}
