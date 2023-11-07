#include "level.h"
#include "collitionSystem.h"
#include <cstring>
#include <cstdio>

Level::Level() {

}

Level::~Level() {
    clearCache();
}

void Level::init(SDL_Renderer* renderer) {
    levelSize = 32;
    Level::renderer = renderer;
    uint8_t dummyLevelData[32][12] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    };
    std::memcpy(currentLevelData, dummyLevelData, 32*12*sizeof(dummyLevelData[0][0]));
    firstColumn = 0;
    lastColumn = 16;
    //initialize blocks vector
    for (int i = 0; i < 17; i++) {
        blocks.push_back(std::vector<Block*>());
    }
    //load first 17 columns
    for (int i = 0; i < 17; i++) {
        loadColumn(i);
    };
}

Level* Level::instance() {
    static Level* instance = new Level();
    return instance;
}

void Level::checkAndCacheTexture(std::string textureResource, std::string cacheId) {
    if (texturesCache.find(cacheId) == texturesCache.end()) {
        SDL_Surface* tempSurface = IMG_Load(textureResource.c_str());
        SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        SDL_FreeSurface(tempSurface);
        texturesCache[cacheId] = tempTexture;
     }
}

void Level::markForDeletion(Entity* entity) {
    entitiesToDelete.push_back(entity);
}

void Level::loadGrid(int h, int w, int columnNumber, int gridNumber, std::vector<SDL_Texture*> tempTextureVector, int id) {
    int x;
    Block* block;
    if (columnNumber != 0) {
        if (columnNumber%17-1 < 0) {
            x = blocks[16][0]->getX() + w;
        }
        else x = blocks[columnNumber%17-1][0]->getX() + w;
    } else x = 0;
    int y = gridNumber * h;
    switch(id)
    {
        case Air:
        case Block_Ground:
            block = new SolidBlock(renderer, x, y, w, h, tempTextureVector, id, CollitionSystem::instance());
            blocks[columnNumber%17].push_back(block);
            break;
        case Block_Brick:
        case Block_Question:
            block = new InteractiveBlock(renderer, x, y, w, h, tempTextureVector, id, CollitionSystem::instance());
            blocks[columnNumber%17].push_back(block);
            break;
        default:
            break;
    }
}

void Level::loadColumn(int columnNumber) {
    std::vector<SDL_Texture*> tempTextureVector;
    tempTextureVector.push_back(NULL);
    loadGrid(BLOCK_BASE_HEIGHT, BLOCK_BASE_WIDTH, columnNumber, -2, tempTextureVector, Air);
    for (int i = 0; i < 12; i++) {
        tempTextureVector.clear();
        switch (currentLevelData[columnNumber][i])
        {
        case Block_Ground:
            checkAndCacheTexture("./media/ground.png", "1A");
            tempTextureVector.push_back(texturesCache["1A"]);
            loadGrid(BLOCK_BASE_HEIGHT, BLOCK_BASE_WIDTH, columnNumber, i, tempTextureVector, Block_Ground);
            break;
        case Block_Brick:
            checkAndCacheTexture("./media/brick.png", "4A");
            tempTextureVector.push_back(texturesCache["4A"]);
            loadGrid(BLOCK_BASE_HEIGHT, BLOCK_BASE_WIDTH, columnNumber, i, tempTextureVector, Block_Brick);
            break;
        case Block_Question:
            checkAndCacheTexture("./media/question1.png", "5A");
            checkAndCacheTexture("./media/question2.png", "5B");
            checkAndCacheTexture("./media/question3.png", "5C");
            tempTextureVector.push_back(texturesCache["5A"]);
            tempTextureVector.push_back(texturesCache["5B"]);
            tempTextureVector.push_back(texturesCache["5C"]);
            loadGrid(BLOCK_BASE_HEIGHT, BLOCK_BASE_WIDTH, columnNumber, i, tempTextureVector, Block_Question);
        case 0:
            break;
        default:
            break;
        }
    }
}

void Level::deleteColumn(int columnNumber) {
    std::vector<Block*>::iterator block;
    int columnToDelete;
    columnToDelete = columnNumber%17;
    for (block = blocks[columnToDelete].begin(); block != blocks[columnToDelete].end(); block++) {
        delete *block;
    }
    blocks[columnToDelete].clear();
}

void Level::horizontalMovement(int playerCurrentSpeed) {
    std::vector<Block*>::iterator block;
    for (int i = 0; i < 17; i++) {
        for (block = blocks[i].begin(); block < blocks[i].end(); block++) {
            (*block)->screenMovement(playerCurrentSpeed);
        }
    }
}

bool Level::detectLoadNewColumn() {
    return blocks[lastColumn%17][0]->getX() + BLOCK_BASE_WIDTH < screenW && lastColumn != levelSize;
}

bool Level::checkEndOfLevel() {
    return lastColumn == levelSize;
}

void Level::loadNewColumn() {
    deleteColumn(firstColumn);
    firstColumn++;
    lastColumn++;
    loadColumn(lastColumn);
}

std::vector<std::vector<Block*>> Level::getBlocks() {
    return blocks;
}

void Level::clearCache() {
    for (auto entityTexture = texturesCache.begin(); entityTexture != texturesCache.end(); entityTexture++) {
        SDL_DestroyTexture(entityTexture->second);
    }
    
    texturesCache.clear();
}