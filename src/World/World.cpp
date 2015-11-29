#include "Utilities/Constants.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Point3d.h"
#include "Utilities/Normal.h"
#include "Utilities/Ray.h"
#include "UserInterface/RenderInterface.h"
#include "World/World.h"
#include "Lights/Ambient.h"
#include "stb/stb_image_write.h"

#include <iostream>


#include "Build/BuildShadedSimple.cpp"


World::World():
   background_color(black),
   tracer_ptr(nullptr),
   camera_ptr(nullptr),
   ambient_ptr(new Ambient)
{
   //@TODO find out what's getting not copied correctly
   //objects.reserve(100);
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
//   objects.reserve(objects.size() + 1);
}

inline void World::add_light(Light * l)
{
   lights.push_back(l);
}
inline void World::set_ambient_light(Ambient * amb)
{
   if(ambient_ptr)
      delete ambient_ptr;
   ambient_ptr = amb->clone();
}
inline void World::set_camera(Camera * camera)
{
   if(camera_ptr)
      delete camera_ptr;
   this->camera_ptr = camera;
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


ShadeRec World::hit_objects(const Ray & ray) const
{
   ShadeRec sr (*this);
   Normal normal;
   Point3D local_hit_point;
   double t;
   double tMin = kHugeValue;
   int num_objects = objects.size();

   for(int i = 0; i < num_objects; i++)
   {
      if(objects[i]->hit(ray,t,sr) && t < tMin)
      {
         sr.hit_an_object = true;
         tMin = t;
         sr.material_ptr = objects[i]->get_material();
         sr.hit_point = ray.o + t * ray.d;
         normal = sr.normal;
         local_hit_point = sr.local_hit_point;
      }
   }
   if(sr.hit_an_object)
   {
      sr.t = tMin;
      sr.normal = normal;
      sr.local_hit_point = local_hit_point;
   }
   return sr;
}