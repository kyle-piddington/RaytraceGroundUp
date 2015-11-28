#include "Tracers/Tracer.h"
#include "Utilities/Constants.h"
Tracer::Tracer(void)
   :world_ptr(nullptr)
   {

   }
Tracer::Tracer(World * w_ptr) 
   :world_ptr(w_ptr)
   {

   }

Tracer::~Tracer()
{
   if(world_ptr)
   {
      world_ptr = nullptr;
   }
}
RGBColor Tracer::trace_ray(const Ray& ray) const
{
   return (black);
}
RGBColor Tracer::trace_ray(const Ray& ray, const int depth) const
{
   return (black);
}
RGBColor Tracer::trace_ray(const Ray& ray, float & tMin, const int depth) const
{
   return (black);
}