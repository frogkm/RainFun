#include "Player.h"

Player :: Player(SDL_Renderer* rend, string imagePath) : GameObject(rend, IMG_Load(const_cast<char*>(imagePath.c_str()))) {

      alive = true;
      speed = 10;
    }

void Player :: keepInBounds(){
  // right boundary
  if (rect.x + rect.w > sW)
     rect.x = sW - rect.w;
  // left boundary
  if (rect.x < 0)
          rect.x = 0;
}

    int Player :: getSpeed(){
      return speed;
    }
