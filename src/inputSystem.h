#ifndef _H_INPUTSYSTEM
#define _H_INPUTSYSTEM

#include <map>
#include "player.h"
#include <SDL2/SDL.h>
#include "global.h"

class InputSystem {
    public:
        void activateActions();
        void setActions(std::map<uint8_t, SDL_Scancode> inputMap);
        std::map<uint8_t, bool> getActiveActiones();
    private:
        std::map<uint8_t, SDL_Scancode> inputMap;
        std::map<uint8_t, bool> activeActions;
        void resetActions();
};

#endif