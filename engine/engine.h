#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

class Rect{
    private:
        int mX, mY;
        unsigned mW,mH;
    public:
        Rect(int x,int y,unsigned w,unsigned h) {
            mX = x;
            mY = y;
            mW = w;
            mH = h;
        }
        int x() const
        {
            return mX;
        }
        int y() const
        {
            return mY;
        }
        unsigned w() const
        {
            return mW;
        }
        unsigned h() const
        {
            return mH;
        }
};
class Size2d{
        unsigned mW,mH;
    public:
        Size2d(unsigned w,unsigned h) {
            mW = w;
            mH = h;
        }
        unsigned w() const
        {
            return mW;
        }
        unsigned h() const
        {
            return mH;
        }
};

class Camera;
class TextureLoader;
class InputManager;
class MapManager;


class Engine{
public:
    Engine();
        virtual ~Engine();
        virtual std::shared_ptr<Camera> createCamera(const char* title, unsigned x, unsigned y,unsigned width, unsigned height) = 0;
        virtual std::shared_ptr<TextureLoader> textureLoader() = 0;
        virtual std::shared_ptr<InputManager> inputManager() = 0;
        virtual std::shared_ptr<MapManager> mapManager() = 0;
};

#endif // ENGINE_H
