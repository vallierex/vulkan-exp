#include "window.h"

#include <stdexcept>

Window::Window(const std::string &title, const int width, const int height) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        throw std::runtime_error(std::string("SDL_Init failed: ") + SDL_GetError());
    }

    SDL_Window *sdl_window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_VULKAN);
    if (!sdl_window) {
        throw std::runtime_error(std::string("SDL_CreateWindow failed: ") + SDL_GetError());
    }

    window_.reset(sdl_window);
}

Window::~Window() {
    SDL_Quit();
}
