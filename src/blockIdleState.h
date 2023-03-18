#ifndef _H_BLOCKIDLESTATE
#define _H_BLOCKIDLESTATE

#include "interactiveBlockState.h"

class BlockState;


class BlockIdleState : public BlockState {
        virtual void update(InteractiveBlock* block);
        virtual void onEntry(InteractiveBlock* block);
        virtual BlockState* handleFromUpCollision(InteractiveBlock* block);
        virtual BlockState* handleFromSideCollision(InteractiveBlock* block);
        virtual BlockState* handleFromDownCollision(InteractiveBlock* block);
        virtual BlockState* handleNoCollision(InteractiveBlock* block);
};

#endif