#ifndef __ViewPlane_H__
#define __ViewPlane_H__
class ViewPlane {
public:
   int hRes; //Horizontal image resolution
   void set_hRes(int hRes);

   int vRes; //Vertical image resolution
   void set_vRes(int vRes);

   float s; //Pixel size
   void set_pixel_size(float pxSize);

   float gamma; //Monitor gamma factor;
   float inv_gamma; // One over gamma;
   void set_gamma(float gamma);
};
#endif