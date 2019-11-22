#include "sdlcamera.h"

SDLCamera::SDLCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height, uint32_t flags):Camera(width,height)
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        mWindow = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            static_cast<int>(width),
            static_cast<int>(height),
            SDL_WINDOW_SHOWN | flags
        );
        if (mWindow) {
            mRenderer = new SDLRenderer();
        }
    }



}

SDLCamera::~SDLCamera()
{

}

Renderer *SDLCamera::renderer(){
    return mRenderer;
}

SDL_Window *SDLCamera::windows(){
    return mWindow;
}
