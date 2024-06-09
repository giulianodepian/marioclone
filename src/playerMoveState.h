#ifndef _H_PLAYERMOVESTATE
#define _H_PLAYERMOVESTATE
#include "global.h"
#include <memory>
#include <SDL2/SDL.h>

class Player;

class PlayerState {
    public:
        virtual ~PlayerState() {};
        virtual std::unique_ptr<PlayerState> handleInput(Player* player) = 0; 
        virtual void update(Player* player) = 0;
        virtual void onEntry(Player* player) = 0;
        virtual std::unique_ptr<PlayerState> handleFromUpCollision(Player* player) = 0;
        virtual std::unique_ptr<PlayerState> handleFromSideCollision(Player* player) = 0;
        virtual std::unique_ptr<PlayerState> handleFromDownCollision(Player* player) = 0;
        virtual std::unique_ptr<PlayerState> handleNoCollision(Player* player) = 0;
};

#endif