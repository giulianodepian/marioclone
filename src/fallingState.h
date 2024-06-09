#ifndef _H_FALLINGSTATE
#define _H_FALLINGSTATE

#include "playerMoveState.h"

class FallingState : public PlayerState {
        virtual std::unique_ptr<PlayerState> handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromUpCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromSideCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromDownCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleNoCollision(Player* player);
};

#endif