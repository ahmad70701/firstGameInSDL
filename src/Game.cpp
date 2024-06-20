#include "Game.h"
#include <iostream>

Game::Game():running(false),gameWindow(nullptr),mainRenderer(nullptr){}
Game::~Game(){
    cleanUp();
}
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen){flags = SDL_WINDOW_FULLSCREEN;}
    //attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "SDL init success";
        gameWindow = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        
        if(gameWindow!=0){
            mainRenderer = SDL_CreateRenderer(gameWindow,-1,0);
            if(mainRenderer!=0){
                std::cout << "Game Renderer created!";
                SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
            }else{
                std::cout << "Render init failed!";
                return false;
            }
        }else{
            std::cout << "Game window init failed!";
            return false;
        }
    }else{
        std::cout << "SDL init failed";
        return false;
    }
    std::cout << "Game init success!";
    running = true;
    return true;
}

void Game::handleEvents(){
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch (event.type){
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
        }
    }
}

void Game::render(){
    SDL_RenderClear(mainRenderer);
    SDL_RenderPresent(mainRenderer);
}

void Game::cleanUp(){
    if (mainRenderer) {
        SDL_DestroyRenderer(mainRenderer);
        mainRenderer = nullptr;
    }
    if (gameWindow) {
        SDL_DestroyWindow(gameWindow);
        gameWindow = nullptr;
    }
    SDL_Quit();
    std::cout << "Game cleaned up!" << std::endl;
}