#ifndef __RENDER_INTERFACE_H__
#define __RENDER_INTERFACE_H__
#endif

/**
 * Provide an interface to write to some user facing output.
 */
class RenderInterface
{
public:
   RenderInterface(World * w);
   virtual void set_pixel(int x, int y, int red, int green, int blue);
protected:
   World * w;
}