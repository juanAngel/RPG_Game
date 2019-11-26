#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <memory>

#include <SDL2/SDL_keyboard.h>

class QuitEventListener{
    public:
        virtual ~QuitEventListener();
        virtual void operator()() = 0;
};
class AppEventListener{
    public:
        virtual ~AppEventListener();
        virtual void onTerminating(){}
        virtual void onLowMemory(){}
        virtual void onWillEnterBackground(){}
        virtual void onDidEnterBackground(){}
        virtual void onWillEnterForeground(){}
        virtual void onDidEnterForeground(){}
};
class KeyEventListener{
    public:
        KeyEventListener() {}
        virtual ~KeyEventListener();
        virtual void onUp(bool repeat, SDL_Keysym keysym){(void)repeat;(void)keysym;}
        virtual void onDown(bool repeat, SDL_Keysym keysym){(void)repeat;(void)keysym;}
};
class MouseEventListener{
    public:
        virtual ~MouseEventListener();
        virtual void onMotion(){}
        virtual void onWheel(){}
        virtual void onButtonDown(){}
        virtual void onButtonUp(){}
};

class InputManager{
    private:
        std::shared_ptr<QuitEventListener> mQuitEventListener;
        std::shared_ptr<AppEventListener> mAppEventListener;
        std::shared_ptr<KeyEventListener> mKeyEventListener;
        std::shared_ptr<MouseEventListener> mMouseEventListener;
    public:
        InputManager();
        virtual ~InputManager();
        virtual void handle() = 0;
        
        void registerQuitEventListener(std::shared_ptr<QuitEventListener> l){
            mQuitEventListener = l;
        }
        void registerAppEventListener(std::shared_ptr<AppEventListener> l){
            mAppEventListener = l;
        }
        void registerKeyEventListener(std::shared_ptr<KeyEventListener> l){
            mKeyEventListener = l;
        }
        void registerMouseEventListener(std::shared_ptr<MouseEventListener> l){
            mMouseEventListener = l;
        }
        //void registerJoystickEventListener();
        //void registerGameControllerEventListener();
        //void registerTouchEventListener();
        //void registerGestureEventListener();


        std::shared_ptr<QuitEventListener> quitEventListener() const
        {
            return mQuitEventListener;
        }
        std::shared_ptr<AppEventListener> appEventListener() const
        {
            return mAppEventListener;
        }
        std::shared_ptr<KeyEventListener> keyEventListener() const
        {
            return mKeyEventListener;
        }
        std::shared_ptr<MouseEventListener> mouseEventListener() const
        {
            return mMouseEventListener;
        }
};

#endif // INPUTMANAGER_H
