#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>

#include <renderer.h>


class Camera{
    private:
        unsigned mPosX,mPosY;
    public:
        Camera(unsigned width, unsigned height);
        virtual ~Camera();
        virtual Renderer* renderer() = 0;
        void moveTo();
        unsigned posX();
        unsigned posY();

};

#endif // CAMERA_H
