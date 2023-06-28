#ifndef _H_BLOCKBOUNCINGSTATE
#define _H_BLOCKBOUNCINGSTATE

#include "interactiveBlockState.h"


class BlockBouncingState : public BlockState {
        virtual void update(InteractiveBlock* block);
        virtual void onEntry(InteractiveBlock* block);
        virtual BlockState* handleFromUpCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual BlockState* handleFromSideCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual BlockState* handleFromDownCollision(InteractiveBlock* block, Entity* dstEntity);
        virtual BlockState* handleNoCollision(InteractiveBlock* block);
};

#endif