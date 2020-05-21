#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
//#include "Values.h"

class Player {
  private:
    bool alive;
    int speed;
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Renderer* rend;

  public:
    Player(SDL_Renderer* rend){
      alive = true;
      speed = 300;
      surface = IMG_Load("Resources/Player.png");
      this->rend = rend;
      texture = SDL_CreateTextureFromSurface(rend, surface);
      SDL_FreeSurface(surface);
      SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
      rect.x = (1000 - rect.w) / 2;
      rect.y = 1000 - rect.h;
    }

    void draw(){
      SDL_RenderCopy(rend, texture, NULL, &rect);
    }

    void keepInBounds(){
      // right boundary
      if (rect.x + rect.w > 1000)
          rect.x = 1000 - rect.w;

      // left boundary
      if (rect.x < 0)
          rect.x = 0;
    }

    SDL_Rect getRect(){
      return rect;
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
