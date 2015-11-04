/**
 * Entry point of Raytracer Application
 */

#include "World/World.h"

int main(int argc, char * argv[])
{
   World w;
   w.build();
   w.render_scene();
   w.export_scene("Render1.png");
   return 0;
}