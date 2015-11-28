#ifndef __RAYCAST_H__
#define __RAYCAST_H__
#include "Tracer.h"
class Raycast : public Tracer
{
public:
   Raycast();
   Raycast(World * w_ptr);
   virtual RGBColor trace_ray(const Ray & ray, const int depth) const;
};
#endif