
#include "sdlengine.h"
#include <SDL/sdlcamera.h>

SDLEngine::SDLEngine()
{

}

Camera *SDLEngine::createCamera(const char *title, unsigned x, unsigned y, unsigned width, unsigned height){
    return new SDLCamera(title,x,y,width,height,0);
}
