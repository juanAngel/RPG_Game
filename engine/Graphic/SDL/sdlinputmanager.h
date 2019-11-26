#ifndef SDLINPUTMANAGER_H
#define SDLINPUTMANAGER_H

#include <Manager/inputmanager.h>

class SDLInputManager : public InputManager{
    public:
        SDLInputManager();

        // InputManager interface
        virtual void handle();
};

#endif // SDLINPUTMANAGER_H
