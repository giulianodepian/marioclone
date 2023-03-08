#ifndef _H_JUMPSTATE
#define _H_JUMPSTATE

#include "playerMoveState.h"

class JumpState : public PlayerState {
        virtual PlayerState* handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
        virtual PlayerState* handleFromUpCollision(Player* player);
        virtual PlayerState* handleFromSideCollision(Player* player);
        virtual PlayerState* handleFromDownCollision(Player* player);
        virtual PlayerState* handleNoCollision(Player* player);
};

#endif