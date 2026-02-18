#include <SDL3/SDL.h>
#include <SDL3/SDL_opengl.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        printf("Press Enter to exit...\n");
        getchar();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL3 OpenGL Test", 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        printf("Unable to create window: %s\n", SDL_GetError());
        SDL_Quit();
        printf("Press Enter to exit...\n");
        getchar();
        return 1;
    }

    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    if (!gl_context) {
        printf("Unable to create OpenGL context: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        printf("Press Enter to exit...\n");
        getchar();
        return 1;
    }

    printf("SDL3 OpenGL window created. Close the window to exit.\n");
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f); // Set clear color
        glClear(GL_COLOR_BUFFER_BIT);           // Clear the screen
        SDL_GL_SwapWindow(window);              // Swap buffers
        SDL_Delay(16);
    }

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}