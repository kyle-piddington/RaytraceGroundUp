/**
 * Entry point of Raytracer Application
 */

#include "World/World.h"
#include "UserInterface/STBIRenderer.h"
#include "Samplers/Regular.h"
#include "Samplers/Jittered.h"
#include <string.h>
#include <iostream>
int main(int argc, char * argv[])
{
   World w;
   STBIRenderer renderer(&w);

   w.build();
   w.vp.set_sampler(new Regular(16));
   w.render_scene();
   renderer.export_image("Render2_Regular.tga");
   w.vp.set_sampler(new Jittered(16));
   w.render_scene();
   renderer.export_image("Render2_Jittered.tga");
   
   return 0;
}