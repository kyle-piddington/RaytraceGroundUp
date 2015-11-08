/**
 * Entry point of Raytracer Application
 */

#include "World/World.h"
#include "UserInterface/STBIRenderer.h"
#include "Samplers/Regular.h"
#include "Samplers/NRooks.h"
#include "Samplers/Jittered.h"
#include "Samplers/MultiJittered.h"
#include <string.h>
#include <iostream>
int main(int argc, char * argv[])
{
   World w;
   STBIRenderer renderer(&w);

   w.build();
   w.vp.set_sampler(new Regular(1));
   w.render_scene();
   renderer.export_image("Render2_MJittered.png");
   return 0;
}