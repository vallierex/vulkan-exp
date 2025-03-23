#ifndef VULKAN_RENDERER_H
#define VULKAN_RENDERER_H
#include <SDL3/SDL_vulkan.h>

#include "window.h"


class VulkanRenderer {
    const Window &window_;

    VkInstance instance_{};
    VkSurfaceKHR surface_{};

    void create_instance();

    void create_surface();

    void init_vulkan();

public:
    void draw_frame();

    explicit VulkanRenderer(const Window &window);

    ~VulkanRenderer();
};


#endif //VULKAN_RENDERER_H
