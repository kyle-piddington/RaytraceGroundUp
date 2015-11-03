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
RGBColor Tracer::trace_ray(const Ray& ray) const
{
   return (black);
}