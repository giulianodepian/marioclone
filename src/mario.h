#ifndef _H_MARIO
#define _H_MARIO

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"
#include "level.h"
#include "block.h"

class Mario {
    public:
        Mario();
        ~Mario();
        void execute();
        void input();
        void update();
        void render();
    
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        Player* player;
        Level* level;
        bool exitProgram;
};

#endif