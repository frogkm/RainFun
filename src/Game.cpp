#include "Game.h"

Game :: Game() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      printf("error initializing SDL: %s\n", SDL_GetError());
  }
  win = SDL_CreateWindow("GAME", // creates a window
                                     SDL_WINDOWPOS_CENTERED,
                                     SDL_WINDOWPOS_CENTERED,
                                     sW, sH, 0);
  rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  player = new Player(rend, "Resources/Player.png");
  running = true;
  count = 0;
  min = 0;
  max = 60;
  countLimit = min + (rand() % (max - min));

  while(running){
    loop();
  }

  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
}

void Game :: loop(){
  count ++;
  if(count >= countLimit){
    rainDrops.push_back(new RainDrop(rend, "Resources/RainDrop.png"));
    countLimit = min + (rand() % (max - min));
    if(max > 10){
      max -= 1;
    }
    count = 0;
  }
  checkKeyboard();
  player -> keepInBounds();
  for(int i = 0; i < rainDrops.size(); i ++){
    if(!rainDrops[i]->fall()){
      rainDrops.erase(rainDrops.begin() + i);
    }
  }
  checkCollision();
  draw();
}

void Game :: checkCollision(){

  for(int i = 0; i < rainDrops.size(); i ++){
    if(SDL_HasIntersection(rainDrops[i]->getRect(), player->getRect())){
      cout << "you got rect" << endl;
      rainDrops.erase(rainDrops.begin() + i);
      collided();
    }
  }
}

void Game :: collided(){
  running = false;
}

void Game :: draw(){
  SDL_RenderClear(rend);
  player->draw(rend);
  for(RainDrop* rainDrop : rainDrops){
    rainDrop ->draw(rend);
  }

  SDL_RenderPresent(rend);
  SDL_Delay(1000 / 60);
}

void Game :: checkKeyboard(){
  const Uint8* keys;
  SDL_PumpEvents();
  keys = SDL_GetKeyboardState(NULL);

  if (SDL_QuitRequested()){
    running = false;
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
    player->setX(player->getX() - player->getSpeed());
  }
  if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
    player->setX(player->getX() + player->getSpeed());
  }

}
