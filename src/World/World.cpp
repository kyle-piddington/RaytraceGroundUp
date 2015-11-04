#include "Utilities/Constants.h"
#include "Utilities/Vector3D.h"
#include "Utilities/Point3d.h"
#include "Utilities/Normal.h"
#include "Utilities/Ray.h"
#include "UserInterface/RenderInterface.h"
#include "World/World.h"
#include "stb/stb_image_write.h"
#include "Build/BuildRedSphere.cpp"


World::World()
{

}


void World::display_pixel(const int row,  const int col,const RGBColor & color) const
{
   paintArea->set_pixel(row,col,color.r * 255,color.b * 255,color.g * 255);
}

void World::open_window(const int vRes, const int hRes) const
{
   paintArea->prepare(vRes, hRes);
}

void World::render_scene(void) const
{
   RGBColor pixel_color;
   Ray ray;
   double zw      = 100.0;
   double x, y;
   open_window(vp.vRes, vp.hRes);
   //Do the main ray trace!
   ray.d = Vector3D(0,0,-1);
   for(int r = 0; r < vp.vRes; r++)
   {
      for(int c = 0; c <= vp.hRes; c++)
      {
         x  = vp.s * (c - 0.5 * (vp.hRes - 1.0)); // Get the X position in the world 
         y  = vp.s * (r - 0.5 * (vp.vRes - 1.0));
         ray.o = Point3D(x,y,zw);
         pixel_color = tracer_ptr->trace_ray(ray);
         display_pixel(r,c,pixel_color);
      }
   }
}
