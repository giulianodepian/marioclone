#include "mario.h"
#include "global.h"
#include "collitionSystem.h"
#include <cstdio>
    
float deltaTime = 0;
float lastUpdateTime = 0;
int screenW = 0;
int screenH = 0;
int framesPassed = 0;
const uint8_t* keyboardState;


Mario::Mario(){
    exitProgram = false;
    //Init SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    keyboardState = SDL_GetKeyboardState(NULL);
    bool buttonsStatus[3] = {0};
    screenW = 800; //Set Default Screen Width
    screenH = 611; //Set Default Screen Height
    //Create Window
    window = SDL_CreateWindow("Mario", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenW, screenH, SDL_WINDOW_SHOWN);
    //Render Context for Window
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    player = new Player(renderer, CollitionSystem::instance());
    level = Level::instance();
    level->init(renderer);
}

Mario::~Mario() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Mario::execute() {
    while (!exitProgram) {
        input();
        update();
        render();
    }
}

void Mario::input() {
    while (SDL_PollEvent(&event)) {
        switch (event.type)
        {
        case SDL_QUIT:
            exitProgram = true;
            break;
        default:
            break;
        }
    }
}

void Mario::update() {
    //Calculate Delta Time
    uint64_t currentTime = SDL_GetTicks64();
    deltaTime = currentTime - lastUpdateTime;
    
    //lock to 60 fps max
    if (deltaTime >= 16) {
        framesPassed++;
        if (framesPassed == 61) framesPassed = 1;
        //Save last Update for next delta time
        lastUpdateTime = currentTime;

        // player updates
        player->handleInput();
        player->update();

        std::vector<std::vector<Block*>> blocks = level->getBlocks();

        // block updates
        std::vector<Block*>::iterator block;
        for (int i = 0; i < 17; i++) {
            for (block = blocks[i].begin(); block < blocks[i].end(); block++) {
                (*block)->update();
            }
        }


        //function to detect collisions
        player->manageScreenEdgesCollition();
        for (int i = 0; i < 17; i++) {
            for (block = blocks[i].begin(); block < blocks[i].end(); block++) {
                player->detectCollition(*block);
            }
        }
        //react if mario is onAir
        player->onAirManager();

        //level updates 
        if (player->getX() + ( player->getW() / 2) > screenW/2 && !(level->checkEndOfLevel())) {
            player->setX(screenW/2 - (player->getW() / 2));
            level->horizontalMovement(-player->getCurrentXSpeed() * (deltaTime * 0.001));
        }
        if (level->detectLoadNewColumn()) level->loadNewColumn();
    }
}

void Mario::render(){
    //Select Windows Background Color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    //Clear previous screen
    SDL_RenderClear(renderer);
    
    //Player Rendering
    player->render();

    //render Blocks
    std::vector<std::vector<Block*>> blocks = level->getBlocks();
    std::vector<Block*>::iterator block;
    for (int i = 0; i < 17; i++) {
        for (block = blocks[i].begin(); block < blocks[i].end(); block++) {
            (*block)->render();
        }
    }

    //Draws buffer into screen
    SDL_RenderPresent(renderer);
}