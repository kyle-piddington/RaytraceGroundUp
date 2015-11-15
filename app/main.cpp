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
#include "Cameras/Camera.h"
#include <string.h>
#include <iostream>
int main(int argc, char * argv[])
{
   World w;
   STBIRenderer renderer(&w);

   w.build();
   w.vp.set_sampler(new MultiJittered(16));
   w.open_window(w.vp.hRes,w.vp.vRes);
   w.camera_ptr->render_scene(w);
   renderer.export_image("RenderCamera.png");
   return 0;
}