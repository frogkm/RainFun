//==============================================================================
#include "Application.h"

//==============================================================================
Application::Application() {
    Surf_Display = NULL;

    Running = true;

    player = new Player();
}

//------------------------------------------------------------------------------
int Application::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    Application theApp;
    return theApp.OnExecute();
}

//==============================================================================
