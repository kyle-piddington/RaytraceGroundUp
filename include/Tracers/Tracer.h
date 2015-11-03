#ifndef __TRACER_H__
#define __TRACER_H__
#include "World/World.h"
#include "Utilities/RGBColor.h"
class Tracer
{
public:
   Tracer(void);
   Tracer(World * w_ptr);

   virtual RGBColor trace_ray(const Ray& ray) const;

protected:
   World * world_ptr;
};

#endif