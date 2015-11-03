#include "World/ViewPlane.h"

void ViewPlane::set_hRes(int hRes)
{
   this->hRes = hRes;
}

void ViewPlane::set_vRes(int vRes)
{
   this->vRes = vRes;
}

void ViewPlane::set_pixel_size(float pxSize)
{
   this->s = pxSize;
}
void ViewPlane::set_gamma(float gamma)
{
   this->gamma = gamma;
   this->inv_gamma = 1.0/gamma;
}
