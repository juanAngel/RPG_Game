#include "sdlrenderer.h"
#include <Graphic/SDL/sdlcamera.h>
#include <Graphic/SDL/sdltexture.h>
#include <Graphic/SDL/sdlengine.h>

SDLRenderer::SDLRenderer(SDLCamera* camera){
    mRenderer = SDL_CreateRenderer(
            camera->windows(),
            -1,
            SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
        );
    if (!mRenderer) {
        //return false;
    }
}

SDLRenderer::~SDLRenderer(){

}

void SDLRenderer::copy(const Texture &texture, const Rect& srcrect, const Rect& dstrect){
    const SDLTexture& tex = *dynamic_cast<const SDLTexture*>(&texture);

    auto src = recToSDL(srcrect);
    auto dst = recToSDL(dstrect);
    SDL_RenderCopy(mRenderer,tex.texture(),&src,&dst);
}

void SDLRenderer::refresh(){
    SDL_RenderPresent(mRenderer);
}

void SDLRenderer::clear(){
    SDL_RenderClear(mRenderer);
}
