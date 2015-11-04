#include "Tracers/SingleSphere.h"
#include "Utilities/Constants.h"
#include "Utilities/ShadeRec.h"
#include "World/World.h"

SingleSphere::SingleSphere() :
   Tracer()
{

}

SingleSphere::SingleSphere(World * world) :
   Tracer(world)
{

}

RGBColor SingleSphere::trace_ray(const Ray & ray) const
{
   ShadeRec sr (*world_ptr);
   double t;

   if(world_ptr->sphere.hit(ray,t,sr))
      return red;
   else
      return black;
}