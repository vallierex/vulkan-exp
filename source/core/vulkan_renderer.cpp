#include "vulkan_renderer.h"

#include <stdexcept>
#include <vulkan/vulkan_core.h>

#include "vulkan_utils.h"

void VulkanRenderer::create_instance() {
    VkApplicationInfo app_info{
        .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
        .pApplicationName = "SDL3 Vulkan Window",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "No Engine",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = VK_API_VERSION_1_4
    };

    std::vector<const char *> extensions = VulkanUtils::get_sdl_vulkan_extensions(window_.window());

    VkInstanceCreateInfo create_info{
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationInfo = &app_info,
        .enabledExtensionCount = static_cast<uint32_t>(extensions.size()),
        .ppEnabledExtensionNames = extensions.data()
    };

    if (vkCreateInstance(&create_info, nullptr, &instance_) != VK_SUCCESS) {
        throw std::runtime_error("VkCreateInstance failed!");
    }
}

void VulkanRenderer::create_surface() {
    if (!SDL_Vulkan_CreateSurface(window_.window(), instance_, nullptr, &surface_)) {
        throw std::runtime_error("SDL_Vulkan_CreateSurface failed!");
    }
}

void VulkanRenderer::draw_frame() {
    bool quit = false;
    SDL_Event event;
    while (quit != true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
    }
}

void VulkanRenderer::init_vulkan() {
    create_instance();
    create_surface();
}

VulkanRenderer::VulkanRenderer(const Window &window) : window_(window) {
    init_vulkan();
}

VulkanRenderer::~VulkanRenderer() {
    if (surface_ != nullptr) {
        vkDestroySurfaceKHR(instance_, surface_, nullptr);
    }

    if (instance_ != nullptr) {
        vkDestroyInstance(instance_, nullptr);
    }
}
