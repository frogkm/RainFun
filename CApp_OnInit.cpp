//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ){
        return false;
    }

    SDL_Window* window;
    SDL_Renderer* renderer;


    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    /* We must call SDL_CreateRenderer in order for draw calls to affect this window. */
    renderer = SDL_CreateRenderer(window, -1, 0);

    /* Select the color for drawing. It is set to red here. */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    /* Clear the entire screen to our selected color. */
    SDL_RenderClear(renderer);

    /* Up until now everything was drawn behind the scenes.
       This will show the new, red contents of the window. */
    SDL_RenderPresent(renderer);



    if (window == NULL){
        return false;
    }

    return true;
}

//==============================================================================
