#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include <renderer.h>
#include <SDL/sdlcamera.h>
#include <SDL2/SDL.h>


class SDLRenderer : public Renderer{
        SDL_Renderer* mRenderer;
    public:
        SDLRenderer(SDLCamera* camera);
        virtual ~SDLRenderer();
        virtual void copy(Texture* texture, const Rect* srcrect, const Rect* dstrect);
        virtual void refresh();
        virtual void clear();
};

#endif // SDLRENDERER_H
