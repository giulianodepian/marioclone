#ifndef _H_idleState
#define _H_idleState

#include "playerMoveState.h"

class IdleState : public PlayerState {
        virtual PlayerState* handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
        virtual PlayerState* handleFromUpCollision(Player* player);
        virtual PlayerState* handleFromSideCollision(Player* player);
        virtual PlayerState* handleFromDownCollision(Player* player);
        virtual PlayerState* handleNoCollision(Player* player);
};

#endif