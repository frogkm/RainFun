#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Player.h"
#include "RainDrop.h"
#include "Values.h"
#include <vector>

class Game {
  private:
    SDL_Window* win;
    SDL_Renderer* rend;
    Player* player;
    vector<RainDrop*> rainDrops;
    bool running;
    int count;
    int min;
    int max;
    int countLimit;
    void loop();
    void checkKeyboard();
    void draw();
    void checkCollision();
    void collided();

  public:
    Game();
};


#endif