#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

const int sW = 1000;
const int sH = 1000;

int main()
{

    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       sW, sH, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    // creates a surface to load an image into the main memory
    SDL_Surface* surface;

    // please provide a path for your image
    surface = IMG_Load("Resources/Player.png");

    // loads image to our graphics hardware memory.
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    // clears main-memory
    SDL_FreeSurface(surface);

    // let us control our image position
    // so that we can move it with our keyboard.
    SDL_Rect rect;

    // connects our texture with rect to control position
    SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

    // adjust height and width of our image box.


    // sets initial x-position of object
    rect.x = (sW - rect.w) / 2;

    // sets initial y-position of object
    rect.y = sH - rect.h;

    // controls annimation loop
    int close = 0;

    // speed of box
    int speed = 300;

    // annimation loop
    const Uint8* keys;
    while (!close) {
        SDL_PumpEvents();

        keys = SDL_GetKeyboardState(NULL);

        if (SDL_QuitRequested()){
          close = 1;
          continue;
        }

        if (keys[SDL_GetScancodeFromKey(SDLK_a)]) {
          rect.x -= speed / 30;
        }

        if (keys[SDL_GetScancodeFromKey(SDLK_d)]) {
          rect.x += speed / 30;
        }

        // right boundary
        if (rect.x + rect.w > 1000)
            rect.x = 1000 - rect.w;

        // left boundary
        if (rect.x < 0)
            rect.x = 0;

        // clears the screen
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex, NULL, &rect);

        // triggers the double buffers
        // for multiple rendering
        SDL_RenderPresent(rend);

        // calculates to 60 fps
        SDL_Delay(1000 / 60);
    }

    // rectroy texture
    SDL_DestroyTexture(tex);

    // rectroy renderer
    SDL_DestroyRenderer(rend);

    // rectroy window
    SDL_DestroyWindow(win);
    return 0;
}
