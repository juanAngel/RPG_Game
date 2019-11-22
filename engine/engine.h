#ifndef ENGINE_H
#define ENGINE_H

#include <camera.h>

class Rect{
    int x, y;
    unsigned w,h;
    public:
        Rect(int x,int y,unsigned w,unsigned h) {
            this->x = x;
            this->y = y;
            this->w = w;
            this->h = h;
        }
};


class Engine{
    public:
        Engine();
        virtual ~Engine();
        virtual Camera* createCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height) = 0;
};

#endif // ENGINE_H
