#include "Cameras/Camera.h"

Camera::Camera():
eye(Point3D(0,0,0)),
lookAt(Point3D(0,0,-1)),
up(0,1,0)
{
   compute_uvw();
}
Camera::Camera(Point3D eye, Point3D lookAt):
eye(eye),
lookAt(lookAt),
up(0,1,0)
{
   compute_uvw();
}
Camera::~Camera()
{
   
}

void Camera::set_eye(Point3D eye)
{
   this->eye = eye;
}
void Camera::set_eye(float x, float y, float z)
{
   this->eye = Point3D(x,y,z);
}
void Camera::set_lookat(Point3D lookAt)
{
   this->lookAt = lookAt;
}
void Camera::set_lookat(float x, float y, float z)
{
   this->lookAt = Point3D(x,y,z);
}

void Camera::compute_uvw()
{
   w = eye-lookAt;
   w.normalize();
   u = up ^ w;
   u.normalize();
   v = w^u;

}