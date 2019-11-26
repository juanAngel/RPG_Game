#ifndef SDLTEXTURE_H
#define SDLTEXTURE_H

#include <Graphic/texture.h>
#include <SDL2/SDL.h>


class SDLTexture : public Texture{
        SDL_Texture*    mTexture;
    public:
        SDLTexture(SDL_Texture* tex);
        virtual ~SDLTexture();

        SDL_Texture* texture() const;
};

#endif // SDLTEXTURE_H
