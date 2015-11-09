#include "Tracers/MultipleObjects.h"
#include "Utilities/RGBColor.h"
#include "GeometricObjects/Sphere.h"
void World::build()
{
   vp.set_hRes(200);
   vp.set_vRes(200);
   vp.set_pixel_size(1.0);
   vp.set_gamma(1.0);
   background_color = black;
   tracer_ptr = new MultipleObjects(this);
   Sphere * sphere = new Sphere;
   sphere->set_center(0,0,0);
   sphere->set_radius(85.0);
   sphere->set_color(RGBColor(1,0,0));
   add_object(sphere);



}