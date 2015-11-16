#include "Tracers/MultipleObjects.h"
#include "GeometricObjects/Plane.h"
#include "GeometricObjects/Sphere.h"
#include "Cameras/OrthographicCamera.h"
#include "Cameras/Pinhole.h"
void World::build()
{
   vp.set_hRes(200);
   vp.set_vRes(200);
   vp.set_pixel_size(1.0);
   vp.set_gamma(1.0);
   background_color = black;
   tracer_ptr = new MultipleObjects(this);

   Sphere * sphere_ptr = new Sphere();
   sphere_ptr->set_center(0,-25,0);
   sphere_ptr->set_radius(80);
   sphere_ptr->set_color(1,0,0);
   add_object(sphere_ptr);

   sphere_ptr = new Sphere(Point3D(0,30,0),60);
   sphere_ptr->set_color(1,1,0);
   add_object(sphere_ptr);

   Plane * plane_ptr(new Plane(Point3D(0,0,0), Normal(0,1,1)));
   plane_ptr->set_color(0.0,0.3,0.0);
   add_object(plane_ptr);

   //Camera:
   camera_ptr = new Pinhole;
   camera_ptr->set_eye(0,0,100);
   camera_ptr->set_lookat(0,0,0);
   camera_ptr->compute_uvw();

   

}