#ifndef __STBI_RENDERER_H__
#define __STBI_RENDERER_H__
#include "UserInterface/RenderInterface.h"
#include <string>
class STBIRenderer : public RenderInterface
{
public:
   STBIRenderer(World * world);
   ~STBIRenderer();
   virtual void set_pixel(int x, int y, int r, int g, int b);
   virtual void prepare(int width, int height);
   void export_image(std::string fileName);
private:
   char * pixels;
   int width; 
   int height;
};
#endif