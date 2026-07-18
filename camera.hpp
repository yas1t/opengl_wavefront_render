#pragma once

#include "vertex.hpp"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#define UP_VEC glm::vec3(0.0f, 1.0f, 0.0f)
#define NEAR_PLANE 0.1f
#define FAR_PLANE 1000.0f

class camera {
private:

    glm::mat4 view_mat;
    glm::mat4 proj_mat;


    unsigned int uniform_loc;

public:
    float speed;
    float fov;
    float aspect_ratio;

    glm::vec3 pos;
    glm::vec3 front;
    glm::vec3 direction;
    glm::vec3 target;

    camera(unsigned int program, float asp_rat);
    void run();
    void move(GLFWwindow **window);
};
