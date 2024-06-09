#ifndef _H_idleState
#define _H_idleState

#include "playerMoveState.h"

class IdleState : public PlayerState {
        virtual std::unique_ptr<PlayerState> handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromUpCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromSideCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromDownCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleNoCollision(Player* player);
};

#endif