#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <Graphic/renderer.h>
#include <Graphic/camera.h>

#include <memory>

class Drawable{
    public:
        Drawable();
        virtual ~Drawable();
        virtual void draw(Renderer& ren,const Camera& camera) = 0;
        virtual bool isVisible(const Camera& camera);
};

#endif // DRAWABLE_H
