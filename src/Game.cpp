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
  for(int i = 1; i < 6; i ++){
    rainDrops.push_back(new RainDrop(rend, "Resources/RainDrop.png", -(i * 225)));
  }
  running = true;

  while(running){
    loop();
  }

  //SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(win);
}

void Game :: loop(){
  checkKeyboard();
  player -> keepInBounds();
  for(RainDrop* rainDrop : rainDrops){
    rainDrop->fall();
  }
  checkCollision();
  draw();
}

void Game :: checkCollision(){

  for(int i = 0; i < rainDrops.size(); i ++){
    if(SDL_HasIntersection(rainDrops[i]->getRect(), player->getRect())){
      cout << "you got rect" << endl;
      rainDrops.erase(rainDrops.begin() + i);
    }
  }

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
