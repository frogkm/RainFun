#include "RainDrop.h"

    RainDrop :: RainDrop(SDL_Renderer* rend, string imagePath) : GameObject(rend, IMG_Load(const_cast<char*>(imagePath.c_str()))) {
      speed = 10;
      rect.x = rand() % (sW - rect.w);
      rect.y = -rect.h;
    }

    bool RainDrop :: fall(){
      setY(getY() + speed);
      if(getY() > sH){
        return false;
      }
      return true;
    }
