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

    void setX(int x);
    void setY(int y);
    void setW(int w);
    void setH(int h);
    int getX();
    int getY();
    int getW();
    int getH();
    int getSpeed();

};

#endif
