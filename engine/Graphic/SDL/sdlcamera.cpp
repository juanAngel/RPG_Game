#include "sdlcamera.h"
#include <Graphic/SDL/sdlrenderer.h>
#include <Graphic/SDL/sdltextureloader.h>

std::shared_ptr<Renderer> SDLCamera::renderer()
{
    return mRenderer;
}

std::shared_ptr<TextureLoader> SDLCamera::textureLoader()
{
    return mTextureLoader;
}

SDLCamera::SDLCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height, uint32_t flags):Camera(width,height)
{
    mWindow = SDL_CreateWindow(
        title,
        static_cast<int>(x),
        static_cast<int>(y),
        static_cast<int>(width),
        static_cast<int>(height),
        SDL_WINDOW_SHOWN | flags
    );
    if (!mWindow) {
        throw "camera init fallied";
    }
    mRenderer = std::shared_ptr<SDLRenderer>(new SDLRenderer(this));
    mTextureLoader = std::shared_ptr<SDLTextureLoader>(new SDLTextureLoader(mRenderer));

}

SDLCamera::~SDLCamera()
{

}

SDL_Window *SDLCamera::windows(){
    return mWindow;
}
