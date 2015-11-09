#include "Tracers/MultipleObjects.h"
#include "Utilities/Constants.h"
#include "Utilities/ShadeRec.h"
#include "World/World.h"

MultipleObjects::MultipleObjects() :
   Tracer()
{

}

MultipleObjects::MultipleObjects(World * world) :
   Tracer(world)
{

}

RGBColor MultipleObjects::trace_ray(const Ray & ray) const
{
  
   ShadeRec sr = world_ptr->hit_bare_bones_objects(ray);
   if(sr.hit_an_object)
      return sr.color;
   else
      return world_ptr->background_color;
}