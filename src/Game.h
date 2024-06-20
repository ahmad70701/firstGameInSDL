#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

/** 
* \brief This handles the core of the game
*/
class Game{
public:
    Game();
    ~Game();
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void cleanUp();
    bool isRunning() const { return running; }

private:
    bool running;
    SDL_Window *gameWindow;
    SDL_Renderer *mainRenderer;
};
#endif //GAME_H

