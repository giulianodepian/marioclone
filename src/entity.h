#ifndef _H_ENTITY
#define _H_ENTITY

#include "global.h"
#include <SDL2/SDL.h>
#include <vector>

class Entity {
    public:
        virtual ~Entity() {};
        int getX();
        int getY();
        int getW();
        int getH();
        int getId();
        void setX(int x);
        void setY(int y);
        void setW(int w);
        void setH(int h);
        SDL_Texture* getGraphic();
        void render();
        virtual void horizontalMovement(int speed)= 0;
        virtual void detectCollition(Entity* entity) = 0;
        virtual void handleFromUpCollision(Entity* entity) = 0;
        virtual void handleFromSideCollision(Entity* entity, bool isRight) = 0;
        virtual void handleFromRightCollision(Entity* entity) = 0;
        virtual void handleFromLeftCollision(Entity* entity) = 0;
        virtual void handleFromDownCollision(Entity* entity) = 0;
        virtual void handleNoCollision() = 0;
    protected:
        int id;
        int x;
        int y;
        int w;
        int h;
        SDL_Texture *currentTexture;
        std::vector<SDL_Texture*> entityTextures;
        SDL_Renderer *renderer;
};

#endif