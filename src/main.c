#include <SDL3/SDL.h>
#include <stdbool.h>
#include <stdio.h>


int main(int argc, char* argv[]) {
    // Initialize SDL with video support
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // SDL3: Create a window with only title, size, and flags
    SDL_Window* window = SDL_CreateWindow(
        "Hello SDL3",
        640, 480,
        0 // no special flags required
    );

    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // SDL3: Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}