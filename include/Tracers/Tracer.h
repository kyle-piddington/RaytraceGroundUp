#ifndef __TRACER_H__
#define __TRACER_H__

#include "Utilities/RGBColor.h"
#include "Utilities/Ray.h"

class World;

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