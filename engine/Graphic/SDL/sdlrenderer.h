#ifndef SDLRENDERER_H

#define SDLRENDERER_H

#include <Graphic/renderer.h>
#include <Graphic/texture.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

class SDLCamera;


class SDLRenderer : public Renderer{
        SDL_Renderer* mRenderer;
    public:
        SDLRenderer(SDLCamera* camera);
        virtual ~SDLRenderer();
        virtual void copy(const Texture& texture, const Rect &srcrect, const Rect &dstrect);
        virtual void refresh();
        virtual void clear();

        SDL_Renderer* renderer(){
            return mRenderer;
        }
};

#endif // SDLRENDERER_H
