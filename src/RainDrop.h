#ifndef RAINDROP_H
#define RAINDROP_H

#include "GameObject.h"

class RainDrop : public GameObject{
  private:
    int speed;

  public:
    RainDrop(SDL_Renderer* rend, string imagePath);
    
};

#endif
