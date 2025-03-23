#ifndef VULKAN_UTILS_H
#define VULKAN_UTILS_H

#include <SDL3/SDL.h>
#include <vector>


class VulkanUtils {
public:
    static std::vector<const char *> get_sdl_vulkan_extensions(SDL_Window *window);
};


#endif //VULKAN_UTILS_H
