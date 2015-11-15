#include "Cameras/OrthographicCamera.h"
#include "Utilities/Constants.h"
#include <iostream>
void OrthographicCamera::render_scene(World & w)
{
   this->compute_uvw();

   RGBColor pixel_color;
   ViewPlane & vp = w.vp;
   Ray ray;
   Point2D sp, pp;
   ray.d =  -this->w;
   std::cout << "Direction: "  << ray.d.x << ","  
                               << ray.d.y << "," 
                               << ray.d.z << "," << std::endl;
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
            ray.o = Point3D(0,0,eye.z) + 
                    (u  * pp.x) + 
                    (v  * pp.y);

            pixel_color += w.tracer_ptr->trace_ray(ray);
         }
         pixel_color /= vp.get_num_samples();
         w.display_pixel(r,c,pixel_color);
        
         
      }
   }

   
}