#include "sdlrenderer.h"

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

void SDLRenderer::copy(Texture *texture, const Rect *srcrect, const Rect *dstrect){

}

void SDLRenderer::refresh(){

}

void SDLRenderer::clear(){

}
