#ifndef WINDOW_H
#define WINDOW_H

#include <SDL3/SDL.h>
#include <memory>
#include <string>

struct SDLWindowDeleter {
    void operator()(SDL_Window *window) const {
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
};


class Window {
    std::unique_ptr<SDL_Window, SDLWindowDeleter> window_{nullptr};

public:
    Window(const std::string &title, int width, int height);

    ~Window();

    [[nodiscard]] SDL_Window *window() const {
        return window_.get();
    }
};


#endif //WINDOW_H
