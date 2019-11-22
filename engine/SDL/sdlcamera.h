#ifndef SDLCAMERA_H
#define SDLCAMERA_H

#include <camera.h>
#include <SDL/sdlrenderer.h>


class SDLCamera:public Camera{
    private:
        SDLRenderer* mRenderer;
        SDL_Window* mWindow;
    public:
        SDLCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height, uint32_t flags);
        virtual ~SDLCamera();
        virtual Renderer* renderer();

        SDL_Window* windows();
};

#endif // SDLCAMERA_H
