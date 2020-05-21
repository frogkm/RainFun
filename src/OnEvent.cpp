//==============================================================================
#include "Application.h"
#include <iostream>
using namespace std;

//==============================================================================
void Application::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT) {
        Running = false;
    }
    else if(Event->type == SDL_KEYDOWN){
        cout << " KEY DOWN " << endl;
    }
}

//==============================================================================
