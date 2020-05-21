#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
#include "Values.h"

class GameObject {
  
  protected:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Renderer* rend;


  public:
    GameObject(SDL_Renderer* rend, string imagePath){

      surface = IMG_Load(const_cast<char*>(imagePath.c_str()));
      this->rend = rend;
      texture = SDL_CreateTextureFromSurface(rend, surface);
      SDL_FreeSurface(surface);
      SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
      rect.x = (sW - rect.w) / 2;
      rect.y = sH - rect.h;
    }

    void draw(){
      SDL_RenderCopy(rend, texture, NULL, &rect);
    }

    SDL_Rect getRect(){
      return rect;
    }

    SDL_Texture* getTexture(){
      return texture;
    }

};
