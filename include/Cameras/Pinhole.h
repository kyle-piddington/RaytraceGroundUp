#ifndef __PINHOLE_H__
#define __PINHOLE_H__
#include "Cameras/Camera.h"
class Pinhole : public Camera
{
public:
   Pinhole();
   virtual ~Pinhole();
   void set_view_distance(float d);
   void set_zoom(float z);
   Vector3D ray_direction(const Point2D & p) const;
   virtual void render_scene(World & w);

private:
   float d;
   float zoom;
};
#endif