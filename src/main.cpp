
#include <SDL3/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        printf("Press Enter to exit...\n");
        getchar();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL3 Window", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        SDL_Log("Unable to create window: %s", SDL_GetError());
        printf("Press Enter to exit...\n");
        SDL_Quit();
        getchar();
        return 1;
    }

    SDL_Log("SDL3 window created successfully. Close the window to exit.");
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        SDL_Delay(16); // Simple frame limiter
    }

    SDL_Log("Window closed. Exiting program.");
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}