#include "GameObject.h"

class Player : public GameObject {
  private:
    bool alive;
    int speed;

  public:
    Player(SDL_Renderer* rend, string imagePath) : GameObject(rend, imagePath) {

      alive = true;
      speed = 300;

    }


    void keepInBounds(){
      // right boundary
      if (rect.x + rect.w > sW)
          rect.x = sW - rect.w;
      // left boundary
      if (rect.x < 0)
          rect.x = 0;
    }

    void setX(int x){
      rect.x = x;
    }
    void setY(int y){
      rect.y = y;
    }
    void setW(int w){
      rect.w = w;
    }
    void setH(int h){
      rect.h = h;
    }

    int getX(){
      return rect.x;
    }
    int getY(){
      return rect.y;
    }
    int getW(){
      return rect.w;
    }
    int getH(){
      return rect.h;
    }
    int getSpeed(){
      return speed;
    }

};
