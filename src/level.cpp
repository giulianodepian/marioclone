#include "level.h"
#include "collitionSystem.h"
#include <cstring>
#include <cstdio>

Level::Level(SDL_Renderer* renderer) {
    Level::renderer = renderer;
    levelSize = 32;
    int dummyLevelData[32][12] = {
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

void Level::loadColumn(int columnNumber) {
    for (int i = 0; i < 12; i++) {
        Block* block;
        int x;
        int y;
        int h;
        int w;
        switch (currentLevelData[columnNumber][i])
        {
        case Ground:
            w = BLOCK_BASE_WIDTH;
            h = BLOCK_BASE_HEIGHT;
            if (columnNumber != 0) {
                if (columnNumber%17-1 < 0) {
                    x = blocks[16][0]->getX() + BLOCK_BASE_WIDTH;
                }
                else x = blocks[columnNumber%17-1][0]->getX() + BLOCK_BASE_WIDTH;
            }
            else x = 0;
            y = i * BLOCK_BASE_HEIGHT;
            block = new Block(renderer, x, y, w, h, "./media/ground.png", 1, CollitionSystem::instance());
            if (columnNumber != 0) blocks[columnNumber%17].push_back(block);
            else blocks[0].push_back(block);
            break;
        case 0:
            break;
        default:
            break;
        }
        /*
        if (columnNumber != 0) blocks[columnNumber%17].push_back(block);
        else blocks[0].push_back(block);
        */
    }
}

void Level::deleteColumn(int columnNumber) {
    std::vector<Block*>::iterator block;
    int columnToDelete;
    if (columnNumber != 0) columnToDelete = columnNumber%17;
    else columnToDelete = 0;
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