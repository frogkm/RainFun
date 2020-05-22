#include "RainDrop.h"

    RainDrop :: RainDrop(SDL_Renderer* rend, string imagePath, int y) : GameObject(rend, imagePath) {
      speed = 10;
      rect.x = rand() % (sW - rect.w);
      rect.y = y;
    }

    void RainDrop :: fall(){
      setY(getY() + speed);
      checkBounds();
    }

    void RainDrop :: checkBounds(){
      if(getY() > sH){
        setY(-100);
        setX(rand() % (sW - rect.w));
      }
    }
