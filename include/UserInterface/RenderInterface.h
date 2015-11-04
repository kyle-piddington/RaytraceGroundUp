#ifndef __RENDER_INTERFACE_H__
#define __RENDER_INTERFACE_H__
#endif

class World;
/**
 * Provide an interface to write to some user facing output.
 */
class RenderInterface
{
public:
   RenderInterface(World * w);
   virtual ~RenderInterface();
   virtual void set_pixel(int x, int y, int red, int green, int blue) = 0;
   virtual void prepare(int width, int height) = 0;
protected:
   World * world;
};