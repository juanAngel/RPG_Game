
#include "sdlengine.h"
#include <Graphic/SDL/sdlcamera.h>

#include <Graphic/SDL/sdltextureloader.h>
#include <Graphic/SDL/sdlinputmanager.h>

#include <Manager/mapmanager.h>

SDLEngine::SDLEngine(){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        throw "initialize error";
    }
    mInputManager = std::shared_ptr<SDLInputManager>(new SDLInputManager());
    mMapManager = std::shared_ptr<MapManager>(new MapManager());
}

std::shared_ptr<Camera>  SDLEngine::createCamera(const char *title, unsigned x, unsigned y, unsigned width, unsigned height){
    return std::shared_ptr<Camera>(new SDLCamera(title,x,y,width,height,0));
}

std::shared_ptr<TextureLoader> SDLEngine::textureLoader(){
    return mTextureLoader;
}

std::shared_ptr<InputManager> SDLEngine::inputManager(){
    return mInputManager;
}

std::shared_ptr<MapManager> SDLEngine::mapManager(){
    return mMapManager;
}
