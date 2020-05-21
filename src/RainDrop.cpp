#include "GameObject.h"

class RainDrop : public GameObject{
  private:
    int speed;

  public:
    RainDrop(SDL_Renderer* rend, string imagePath) : GameObject(rend, imagePath) {
      speed = 100;
    }
};
