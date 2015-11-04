#ifndef __SINGLE_SPHERE_H__
#define __SINGLE_SPHERE_H__
#include "Tracers/Tracer.h"
class SingleSphere : public Tracer
{
public:
   SingleSphere();
   SingleSphere(World * world);

   RGBColor trace_ray(const Ray & ray) const;
};
#endif