#ifndef SDLENGINE_H
#define SDLENGINE_H

#include <engine.h>

class SDLEngine : public Engine
{
public:
    SDLEngine();
    virtual Camera* createCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height);
};

#endif // SDLENGINE_H
