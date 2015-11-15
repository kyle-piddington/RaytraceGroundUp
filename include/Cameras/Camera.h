#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Utilities/Point3D.h"
#include "Utilities/Vector3D.h"
#include "World/World.h"
class Camera
{
public:
   Camera();
   Camera(Point3D eye, Point3D lookAt);
   
   void set_eye(Point3D eye);
   
   void set_eye(float x, float y, float z);
   
   void set_lookat(Point3D lookAt);
   
   void set_lookat(float x, float y, float z);
   
   void compute_uvw();

   virtual void render_scene(World & w) = 0;
protected:
   Point3D eye;
   Point3D lookAt;
   Vector3D up;
   Vector3D u,v,w;
};
#endif