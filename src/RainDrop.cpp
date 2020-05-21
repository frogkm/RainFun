#include "RainDrop.h"

    RainDrop :: RainDrop(SDL_Renderer* rend, string imagePath) : GameObject(rend, imagePath) {
      speed = 100;
    }
