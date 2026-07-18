#pragma once


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow *window_init(uint16_t scr_w, uint16_t scr_h, const char *name, uint8_t major, uint8_t minor);
// removing minor bloat