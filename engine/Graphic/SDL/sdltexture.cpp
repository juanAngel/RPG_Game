#include "sdltexture.h"

SDLTexture::SDLTexture(SDL_Texture *tex){
    this->mTexture = tex;
}

SDLTexture::~SDLTexture(){
    SDL_DestroyTexture(mTexture);
}

SDL_Texture *SDLTexture::texture() const{
    return mTexture;
}
