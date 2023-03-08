#ifndef _H_PLAYERMOVESTATE
#define _H_PLAYERMOVESTATE
#include "global.h"
#include <SDL2/SDL.h>

class Player;

class PlayerState {
    public:
        virtual ~PlayerState() {};
        virtual PlayerState* handleInput(Player* player) = 0; 
        virtual void update(Player* player) = 0;
        virtual void onEntry(Player* player) = 0;
        virtual PlayerState* handleFromUpCollision(Player* player) = 0;
        virtual PlayerState* handleFromSideCollision(Player* player) = 0;
        virtual PlayerState* handleFromDownCollision(Player* player) = 0;
        virtual PlayerState* handleNoCollision(Player* player) = 0;
};

#endif