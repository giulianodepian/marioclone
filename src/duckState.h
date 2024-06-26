#ifndef _H_DUCKSTATE
#define _H_DUCKSTATE

#include "playerMoveState.h"

class DuckState : public PlayerState {
        virtual std::unique_ptr<PlayerState> handleInput(Player* player); 
        virtual void update(Player* player);
        virtual void onEntry(Player* player);
};

#endif