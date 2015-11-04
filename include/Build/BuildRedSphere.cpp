#include "Tracers/SingleSphere.h"
void World::build()
{
   vp.set_hRes(200);
   vp.set_vRes(200);
   vp.set_pixel_size(1.0);
   vp.set_gamma(1.0);
   background_color = black;
   tracer_ptr = new SingleSphere(this);
   sphere.set_center(0.0);
   sphere.set_radius(85.0);
}