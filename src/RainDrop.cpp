#include "RainDrop.h"

    RainDrop :: RainDrop(SDL_Renderer* rend, string imagePath) : GameObject(rend, imagePath) {
      speed = 10;
      rect.x = rand() % (sW - rect.w);
      rect.y = -100;
    }

    bool RainDrop :: fall(){
      setY(getY() + speed);
      if(getY() > sH){
        return false;
      }
      return true;
    }
