#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Player.h"
#include "RainDrop.h"
#include "Values.h"
#include <vector>

void checkKeyboard(Player* player);
void draw(SDL_Renderer* rend, Player* player);
int close = 0;

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       sW, sH, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    Player* player = new Player(rend, "Resources/Player.png");
    vector<RainDrop*> rainDrops;
    for(int i = 0; i < 5; i ++){
      rainDrops.push_back(new RainDrop(rend, "Resources/RainDrop.png"));
    }

    // annimation loop
    while (!close) {
      checkKeyboard(player);
      player -> keepInBounds();
      draw(rend, player);
    }
    //SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    return 0;
}

void checkKeyboard(Player* player){
  const Uint8* keys;
  SDL_PumpEvents();
  keys = SDL_GetKeyboardState(NULL);

  if (SDL_QuitRequested()){
    close = 1;
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
    player->setX(player->getX() - player->getSpeed() / 30);
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
    player->setX(player->getX() + player->getSpeed() / 30);
  }
}

void draw(SDL_Renderer* rend, Player* player){
  SDL_RenderClear(rend);
  player->draw();
  SDL_RenderPresent(rend);
  SDL_Delay(1000 / 60);
}
