#include "UserInterface/STBIRenderer.h"

STBIRenderer::STBIRenderer(World * world):
   RenderInterface(world)
{
   this->width = world->vp.hRes;
   this->width = world->vp.vRes;
}

void STBIRenderer::export_scene(std::string filename)
{
   const char * fname = filename.c_str();
   stbi_write_image(fname, width, height, 3, pixels, w*3);
}

