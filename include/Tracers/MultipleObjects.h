#ifndef __MULTIPLE_OBJECTSH__
#define __MULTIPLE_OBJECTSH__
#include "Tracers/Tracer.h"
class MultipleObjects : public Tracer
{
public:
   MultipleObjects();
   MultipleObjects(World * world);

   RGBColor trace_ray(const Ray & ray) const;
};
#endif