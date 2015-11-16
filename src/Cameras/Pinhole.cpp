#include "Cameras/Pinhole.h"


#include "Utilities/Constants.h"
#include <iostream>
Pinhole::Pinhole() :
d(40),
zoom(1.0)
{

}
void Pinhole::render_scene(World & w)
{
   this->compute_uvw();

   RGBColor pixel_color;
   ViewPlane & vp = w.vp;
   Ray ray;
   Point2D sp, pp;
   vp.s /= zoom;
   ray.o = this->eye;
   for(int r = 0; r < vp.vRes; r++)
   {
      for(int c = 0; c < vp.hRes; c++)
      {
         pixel_color = black;
         for(int j = 0; j < vp.get_num_samples(); j++)
         {
            sp = vp.get_sampler_ptr()->sample_unit_square();
            pp.x  = vp.s * (c - 0.5 * (vp.hRes - 1.0) + sp.x); // Get the X position in the world 
            pp.y  = vp.s * (r - 0.5 * (vp.vRes - 1.0) + sp.y);
            //std::cout << "Tracing at " << sp.x << "," << sp.y << std::endl;
            ray.d = ray_direction(pp);


            pixel_color += w.tracer_ptr->trace_ray(ray);
         }
         pixel_color /= vp.get_num_samples();
         w.display_pixel(r,c,pixel_color);
        
         
      }
   }
}

Vector3D Pinhole::ray_direction(const Point2D & p) const
{
   Vector3D dir = p.x * u + p.y * v - d*w;
   dir.normalize();
   return dir;
}

void Pinhole::set_view_distance(float d)
{
   this->d = d;
}
void Pinhole::set_zoom(float z)
{
   this->zoom = z;
}