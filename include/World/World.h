#ifndef __WORLD_H__
#define __WORLD_H__
#include "World/ViewPlane.h"
#include "Utilities/RGBColor.h"
#include "GeometricObjects/GeometricObject.h"
#include "Utilities/ShadeRec.h"
#include "Tracers/Tracer.h"
#include "Lights/Light.h"
#include "Lights/Ambient.h"

/**
 * A world contains geometric objects, and 
 * can be renderd to a scene.
 */

class RenderInterface;
class Camera;
class World{
private:


public:
   ViewPlane vp;
   RGBColor background_color;
   RenderInterface * paintArea;    
   Tracer * tracer_ptr;
   Camera * camera_ptr;
   Light * ambient_ptr;
   std::vector<GeometricObject *> objects;
   std::vector<Light *> lights;


   World();

   void build();

   /**
    * Render the world to an image
    */
   void render_scene() const;

   /**
    * Prepare the renderer to display in image
    */
   void open_window(const int vRes, const int hRes) const;
   /**
    * Write pixel_color to the position row/col
    * @param row         the pixel row
    * @param col         the pixel column
    * @param pixel_color the pixel to write data to.
    */
   void display_pixel(const int row,
                      const int col,
                      const RGBColor & pixel_color) const;

    /**
     * Add an object to this world
     */
    inline void add_object(GeometricObject * obj);

    /**
     * Add a light to this world
     */
    inline void add_light(Light * light);

    inline void set_ambient_light(Ambient * ambient);

    inline void set_camera(Camera * cam);

    ShadeRec hit_bare_bones_objects(const Ray& ray) const;
    ShadeRec hit_objects(const Ray & ray) const;
};
#endif