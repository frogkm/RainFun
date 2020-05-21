#include "Player.h"

Player :: Player(SDL_Renderer* rend, string imagePath) : GameObject(rend, imagePath) {

      alive = true;
      speed = 300;

    }


void Player :: keepInBounds(){
  // right boundary
  if (rect.x + rect.w > sW)
     rect.x = sW - rect.w;
  // left boundary
  if (rect.x < 0)
          rect.x = 0;
}

    void Player :: setX(int x){
      rect.x = x;
    }
    void Player :: setY(int y){
      rect.y = y;
    }
    void Player :: setW(int w){
      rect.w = w;
    }
    void Player :: setH(int h){
      rect.h = h;
    }

    int Player :: getX(){
      return rect.x;
    }
    int Player :: getY(){
      return rect.y;
    }
    int Player :: getW(){
      return rect.w;
    }
    int Player :: getH(){
      return rect.h;
    }
    int Player :: getSpeed(){
      return speed;
    }
