#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <renderer.h>
#include <camera.h>


class Drawable{
    public:
        Drawable();
        virtual ~Drawable();
        virtual void draw(Renderer* ren,Camera* camera) = 0;
};

#endif // DRAWABLE_H
