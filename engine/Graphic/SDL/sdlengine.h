#ifndef SDLENGINE_H
#define SDLENGINE_H

#include <engine.h>
#include <SDL2/SDL.h>

class SDLTextureLoader;
class SDLInputManager;

inline SDL_Rect recToSDL(const Rect& rIn){
    SDL_Rect r = {
        .x = rIn.x(),
        .y = rIn.y(),
        .w = static_cast<int>(rIn.w()),
        .h = static_cast<int>(rIn.h())
    };
    return r;
}

class SDLEngine : public Engine{
        std::shared_ptr<SDLTextureLoader> mTextureLoader;
        std::shared_ptr<SDLInputManager> mInputManager;
        std::shared_ptr<MapManager> mMapManager;
    public:
        SDLEngine();

        // Engine interface
        virtual std::shared_ptr<Camera> createCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height);
        virtual std::shared_ptr<TextureLoader> textureLoader();
        virtual std::shared_ptr<InputManager> inputManager();
        virtual std::shared_ptr<MapManager> mapManager();
};

#endif // SDLENGINE_H
