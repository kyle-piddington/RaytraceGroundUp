#ifndef __ORTHOGRAPHIC_CAMERA_H__
#define __ORTHOGRAPHIC_CAMERA_H__
#include "Cameras/Camera.h"
class OrthographicCamera : public Camera
{
   void render_scene(World & w);
};
#endif