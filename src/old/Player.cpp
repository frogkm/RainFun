#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Player {
  private:
    bool alive;
    int speed;
    int xPos;
    int yPos;
    SDL_Surface* image;

  public:
    Player(int speed, SDL_Surface* image, int xPos){
      alive = true;
      this->speed = speed;
      this->xPos = xPos;
      yPos = 300;
      this->image = image;
    }

    Player(){
      alive = true;
      speed = 10;
      xPos = 50;
      yPos = 300;
      //image
    }

    void render(){
      cout << "rendered" << endl;
    }

};
