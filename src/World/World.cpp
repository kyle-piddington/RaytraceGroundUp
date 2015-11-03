#include "Utilities/Constants.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Point3d.h"
#include "Utilities/Normal.h"
#include "Utilities/Ray.h"
#include "Utilities/World.h"

#include "Build/BuildRedSphere.cpp"




void World::render_scene(void) const
{
   RGBColor pixel_color;
   Ray ray;
   double zw      = 100.0;
   double x, y;
   open_window(vp.hRes, vp.vRes);

   //Do the main ray trace!
   for(int r = 0; r < vp.vRes; r++)
   {
      for(int c = 0; c <= vp.hRes; c++)
      {
         x  = vp.s * (c - 0.5 * (vp.hRes - 1.0)); // Get the X position in the world 
         y  = vp.s * (r - 0.5 * (vp.vres - 1.0));
         ray.o = Point3d(x,y,zw);
         pixel_color = tracer_ptr->trace_ray(ray);
         display_pixel(r,c,pixel_color);
      }
   }

}