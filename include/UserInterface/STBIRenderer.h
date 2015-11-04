#ifndef __STBI_RENDERER_H__
#define __STBI_RENDERER_H__
#include "UserInterface/RenderInterface.h"
class STBIRenderer : public RenderInterface
{
public:
   STBIRenderer(World * world)
   ~STBIRenderer()
   virtual void set_pixel(int x, int y, int r, int g, int b);
   void export_image(std::string fileName);
private:
   char * pixels;
   int width; 
   int height;
};
#endif