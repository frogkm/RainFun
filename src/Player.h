#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
  private:
    bool alive;
    int speed;

  public:
    Player(SDL_Renderer* rend, string imagePath);
    void keepInBounds();
    int getSpeed();

};

#endif
