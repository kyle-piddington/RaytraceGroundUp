/**
 * Entry point of Raytracer Application
 */

#include "World/World.h"
#include "UserInterface/STBIRenderer.h"
 #include <string.h>
int main(int argc, char * argv[])
{
   World w;
   STBIRenderer renderer(&w);

   w.build();
   w.render_scene();
   renderer.export_image("Render1.png");
   return 0;
}