#include "Tracers/Raycast.h"
#include "Utilities/ShadeRec.h"
#include "World/World.h"
#include "Materials/Material.h"

Raycast::Raycast():
   Tracer()
{

}
Raycast::Raycast(World * w_ptr) :
   Tracer(w_ptr)
{

}
RGBColor Raycast::trace_ray(const Ray & ray, const int depth) const
{
   ShadeRec sr (world_ptr->hit_objects(ray));
   if(sr.hit_an_object)
   {
      sr.ray = ray;
      return sr.material_ptr->shade(sr);
   }
   else
   {
      return world_ptr->background_color;
   }
}