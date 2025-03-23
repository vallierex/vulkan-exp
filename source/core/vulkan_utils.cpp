#include "vulkan_utils.h"

#include <stdexcept>
#include <SDL3/SDL_vulkan.h>

std::vector<const char *> VulkanUtils::get_sdl_vulkan_extensions(SDL_Window *window) {
    uint32_t extension_count = 0;
    char const *const*extensions = SDL_Vulkan_GetInstanceExtensions(&extension_count);

    if (!extensions) {
        throw std::runtime_error("Failed to get Vulkan extension count");
    }

    return {extensions, extensions + extension_count};
}
