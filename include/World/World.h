#ifndef __WORLD_H__
#define __WORLD_H__
#include "World/ViewPlane.h"
#include "Utilities/RGBColor.h"
#include "GeometricObjects/Sphere.h"
#include "Tracers/Tracer.h"
/**
 * A world contains geometric objects, and 
 * can be renderd to a scene.
 */
class World{

public:
   ViewPlane vp;
   RGBColor background_color;
   Sphere sphere;
   Tracer * tracer_ptr;
   

   World();

   void build();

   /**
    * Render the world to an image
    */
   void render_scene() const;

   void open_window(const int hres, cont in vres) const;

   /**
    * Write pixel_color to the position row/col
    * @param row         the pixel row
    * @param col         the pixel column
    * @param pixel_color the pixel to write data to.
    */
   void display_pixel(const int row,
                      const int col,
                      const RGBColor & pixel_color) const;



};
#endif