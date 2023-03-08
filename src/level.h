#ifndef _H_Level
#define _H_Level
#include <vector>
#include "block.h"
#include "global.h"

class Level{
    public:
        Level(SDL_Renderer* renderer);
        ~Level();
        void horizontalMovement(int playerCurrentSpeed);
        void loadColumn(int columnNumber);
        void deleteColumn(int columnNuber);
        bool detectLoadNewColumn();
        void loadNewColumn();
        std::vector<std::vector<Block*>> getBlocks();
        bool checkEndOfLevel();
    private:
        int currentLevelData[400][12];
        int firstColumn; //Starts in 0
        int lastColumn; //starts in 16
        int levelSize; //In Columns
        std::vector<std::vector<Block*>> blocks;
        // std::vector<entity*> entities; Entities List
        SDL_Renderer* renderer;
};

#endif