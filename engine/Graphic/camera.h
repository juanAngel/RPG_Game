#ifndef CAMERA_H
#define CAMERA_H

#include <stdint.h>

#include <Graphic/renderer.h>
#include <engine.h>


class Camera{
    private:
        int mPosX = 0,mPosY = 0;
        unsigned mWidth, mHeight;
    public:
        Camera(unsigned width, unsigned height);
        virtual ~Camera();
        virtual std::shared_ptr<Renderer> renderer() = 0;
        virtual std::shared_ptr<TextureLoader> textureLoader() = 0;
        void moveTo();
        int posX() const
        {
            return mPosX;
        }
        int posY() const
        {
            return mPosY;
        }
        unsigned width() const
        {
            return mWidth;
        }
        unsigned height() const
        {
            return mHeight;
        }
};

#endif // CAMERA_H
