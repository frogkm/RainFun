#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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

  public:
    GameObject(SDL_Renderer* rend, string imagePath){
      surface = IMG_Load(const_cast<char*>(imagePath.c_str()));
      texture = SDL_CreateTextureFromSurface(rend, surface);
      SDL_FreeSurface(surface);
      SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
      rect.x = (sW - rect.w) / 2;
      rect.y = sH - rect.h;
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

    void draw(SDL_Renderer* rend){
      SDL_RenderCopy(rend, texture, NULL, &rect);
    }

    SDL_Rect* getRect(){
      return &rect;
    }

    SDL_Texture* getTexture(){
      return texture;
    }

};

#endif
