#include "../window.hpp"

GLFWwindow *window_init(uint16_t scr_w, uint16_t scr_h, const char *name, uint8_t major, uint8_t minor) {
    GLFWwindow *win;

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    win = glfwCreateWindow(scr_w, scr_h, name, NULL, NULL);

    if(win == NULL) {
        std::cerr << "error during window creation\n";
        return nullptr;

    }

    glfwMakeContextCurrent(win);

    gladLoadGL();

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glfwSwapInterval(0);
    glViewport(0, 0, scr_w, scr_h);


    return win;
}
