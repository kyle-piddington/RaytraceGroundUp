/**
 * Entry point of Raytracer Application
 */

#include "World/World.h"
#include "UserInterface/STBIRenderer.h"
#include "Samplers/Regular.h"
#include "Samplers/NRooks.h"
#include "Samplers/Jittered.h"
#include "Samplers/MultiJittered.h"
#include "Samplers/Hammersley.h"
#include <string.h>
#include <iostream>
int main(int argc, char * argv[])
{
   World w;
   STBIRenderer renderer(&w);

   w.build();
   w.vp.set_sampler(new Hammersley(16));
   w.render_scene();
   renderer.export_image("Render3.png");
   return 0;
}