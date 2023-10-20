#ifndef _H_Level
#define _H_Level
#include <vector>
#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "block.h"
#include "interactiveBlock.h"
#include "solidBlock.h"
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
        void clearCache();
        void loadGrid(int h, int w, int columnNumber, int gridNumber, std::vector<SDL_Texture*> tempTextureVector, int id);
        void checkAndCacheTexture(std::string textureResource, std::string cacheId);
    private:
        uint8_t currentLevelData[400][12];
        int firstColumn; //Starts in 0
        int lastColumn; //starts in 16
        int levelSize; //In Columns
        std::map<std::string, SDL_Texture*> texturesCache; 
        std::vector<std::vector<Block*>> blocks;
        // std::vector<entity*> entities; Entities List
        SDL_Renderer* renderer;
};

#endif