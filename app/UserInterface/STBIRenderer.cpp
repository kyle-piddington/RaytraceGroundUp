#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "UserInterface/STBIRenderer.h"
#include "World/World.h"
#include "stb/stb_image_write.h"

STBIRenderer::STBIRenderer(World * world):
   RenderInterface(world)
{
}
STBIRenderer::~STBIRenderer()
{
   if(pixels != nullptr)
      delete pixels;
}
void STBIRenderer::set_pixel(int y, int x, int r, int g, int b)
{
   assert(x < this->width && y < this->height && x >= 0 && y >= 0);
   y = (this->height - 1) - y;
   pixels[3*(y*width + x)    ] = r;
   pixels[3*(y*width + x) + 1] = g;
   pixels[3*(y*width + x) + 2] = b;
     
}
void STBIRenderer::prepare(int width, int height)
{
   this->width = world->vp.hRes;
   this->height = world->vp.vRes;
   pixels = new char[this->width*this->height*3];

}


void STBIRenderer::export_image(std::string filename)
{
   const char * fname = filename.c_str();
   stbi_write_png(fname, width, height, 3, pixels, width*3);

}



