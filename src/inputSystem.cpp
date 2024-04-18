#include "inputSystem.h"
#include <iterator>

void InputSystem::activateActions() {
    std::map<uint8_t, SDL_Scancode>::iterator Action;

    resetActions();
    
    for (Action = inputMap.begin(); Action != inputMap.end(); Action++) {
        if (keyboardState[Action->second]) {
            activeActions[Action->first] = true;
        }
    }
}

void InputSystem::setActions(std::map<uint8_t, SDL_Scancode> inputMap) {
    InputSystem::inputMap = inputMap;
}

std::map<uint8_t, bool> InputSystem::getActiveActiones() {
    return activeActions;
}

void InputSystem::resetActions() {
    std::map<uint8_t, bool>::iterator Action;
    for(Action = activeActions.begin(); Action != activeActions.end(); Action++) Action->second = false;
}