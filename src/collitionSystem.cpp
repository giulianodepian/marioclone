#include "global.h"
#include "collitionSystem.h"
#include <cstdio>

void CollitionSystem::detectCollition(Entity* entitySrc, Entity* entityDst) {
    if (entitySrc->getX() + entitySrc->getW() >= entityDst->getX() 
    && entitySrc->getX() <= entityDst->getX() + entityDst->getW()) {
        if (entitySrc->getY() + entitySrc->getH() >= entityDst->getY() - 1 
        && entitySrc->getY() <= entityDst->getY() + entityDst->getH() - 1) {
            int bottomCollition = entityDst->getY() + entityDst->getH() - 1 - entitySrc->getY();
            int topCollition = entitySrc->getY() + entitySrc->getH() - entityDst->getY() - 1;
            int rightCollition = entitySrc->getX() + entitySrc->getW() - entityDst->getX();
            int leftCollition = entityDst->getX() + entityDst->getW() - entitySrc->getX();
            if (topCollition < bottomCollition && topCollition < rightCollition && topCollition < leftCollition) {  
                entitySrc->handleFromUpCollision(entityDst);
            } else if (rightCollition < leftCollition && rightCollition < topCollition && rightCollition < bottomCollition) {
                entitySrc->handleFromRightCollision(entityDst);
            } else if (leftCollition < rightCollition && leftCollition < topCollition && leftCollition < bottomCollition) {
                entitySrc->handleFromLeftCollision(entityDst);
            } else {
                entitySrc->handleFromDownCollision(entityDst);
            }
        }
    }
}

CollitionSystem* CollitionSystem::instance() {
    static CollitionSystem* instance = new CollitionSystem();
    return instance;
}

CollitionSystem::CollitionSystem() {}