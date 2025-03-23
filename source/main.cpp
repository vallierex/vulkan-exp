#include <cstdlib>
#include <SDL3/SDL.h>

#include "core/vulkan_renderer.h"
#include "core/window.h"

int main(int argc, char *argv[]) {
    const Window window("Vulkan", 800, 600);
    VulkanRenderer renderer(window);
    renderer.draw_frame();

    return EXIT_SUCCESS;
}
