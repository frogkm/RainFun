#include <SDL2/SDL.h>
#include "Player.cpp"

class Application {
    private:
        bool Running;

        SDL_Surface* Surf_Display;

        Player* player;

    public:
        Application();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};
