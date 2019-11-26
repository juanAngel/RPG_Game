#ifndef SDLCAMERA_H
#define SDLCAMERA_H

#include <Graphic/camera.h>
#include <SDL2/SDL.h>

class SDLRenderer;
class SDLTextureLoader;

class SDLCamera:public Camera{
    private:
        SDL_Window* mWindow;
        std::shared_ptr<SDLRenderer> mRenderer;
        std::shared_ptr<SDLTextureLoader> mTextureLoader;
    public:
        SDLCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height, uint32_t flags);
        virtual ~SDLCamera();

        SDL_Window* windows();
        virtual std::shared_ptr<Renderer> renderer();
        virtual std::shared_ptr<TextureLoader> textureLoader();
};

#endif // SDLCAMERA_H
