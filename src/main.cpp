//
// Created by mrtuxa on 7/16/23.
//

#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "include/screen.hpp"

int main() {
    SDL_Window* window = nullptr;

    SDL_Surface* surface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_ERROR: " << SDL_GetError() << std::endl;
    } else {
        window = SDL_CreateWindow("SDL First App", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen::width, screen::height, SDL_WINDOW_SHOWN);

        if (window == nullptr) {
            std::cout << "Window could not be created! SDL_ERROR: " << SDL_GetError() << std::endl;
        } else {
            surface = SDL_GetWindowSurface( window );
            SDL_FillRect( surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface( window );

            SDL_Event e; bool quit = false; while(!quit){ while( SDL_PollEvent(&e ) ){ if(e.type == SDL_QUIT ) quit = true; } }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
