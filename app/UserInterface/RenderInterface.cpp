#include "World/World.h"
#include "UserInterface/RenderInterface.h"
RenderInterface::RenderInterface(World * world):
   world(world)
{
   world->paintArea = this;
}
RenderInterface::~RenderInterface()
{

}
