#ifndef _H_MOVINGSTATE
#define _H_MOVINGSTATE

#include "playerMoveState.h"

class MovingState : public PlayerState {
        virtual std::unique_ptr<PlayerState> handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromUpCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromSideCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleFromDownCollision(Player* player);
        virtual std::unique_ptr<PlayerState> handleNoCollision(Player* player);
};

#endif