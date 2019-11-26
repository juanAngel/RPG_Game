#include "sdlinputmanager.h"
#include <SDL2/SDL.h>

SDLInputManager::SDLInputManager()
{
    
}

void SDLInputManager::handle(){
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                if(quitEventListener())
                    (*quitEventListener())();
                break;
        }
    }
}
