#include "../camera.hpp"

camera::camera(unsigned int program, float asp_rat) {
    fov = 90.0f;
    aspect_ratio = asp_rat;

    pos = glm::vec3(0.0f, 1.0f, 5.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    right = glm::normalize(glm::cross(front, up));

    view_mat = glm::mat4(1.0f);
    proj_mat = glm::mat4(1.0f);

    view_mat = glm::lookAt(pos, pos + front, UP_VEC);
    proj_mat = glm::perspective(glm::radians(fov), aspect_ratio, NEAR_PLANE, FAR_PLANE);

    glUseProgram(program);
    uniform_loc = glGetUniformLocation(program, "camera_matrix");
    glUniformMatrix4fv(uniform_loc, 1, GL_FALSE, glm::value_ptr(proj_mat * view_mat));

}

void camera::run() {
    view_mat = glm::lookAt(pos, pos+front, UP_VEC);

    proj_mat = glm::perspective(glm::radians(fov), aspect_ratio, NEAR_PLANE, FAR_PLANE);

    speed = 0.01f;

    glUniformMatrix4fv(uniform_loc, 1, GL_FALSE, glm::value_ptr(proj_mat * view_mat));
}
void camera::move(GLFWwindow **window) {

    float oneoversqrtthree = 1/(glm::sqrt(3.0f));
    float oneoversqrttwo = 1/(glm::sqrt(2.0f));
    bool sticky = false;
    if(glfwGetKey(*window, GLFW_KEY_W) == GLFW_PRESS) {

        posz = -1;
    }
    if(glfwGetKey(*window, GLFW_KEY_S) == GLFW_PRESS) {
        posz = 1;

    }
    if(glfwGetKey(*window, GLFW_KEY_UP) == GLFW_PRESS) {

        posy = 1;
    }
    if(glfwGetKey(*window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        posy = -1;
    }
    if (glfwGetKey(*window, GLFW_KEY_A) == GLFW_PRESS) {
        posx = -1;
    }
    if (glfwGetKey(*window, GLFW_KEY_D) == GLFW_PRESS) {
        posx = 1;
    }
    float multiplier = 1;
    if (posx != 0 && posy != 0 && posz != 0)  {
        multiplier = oneoversqrtthree;
    } else if ((posx != 0 && posy != 0) || (posx != 0 && posz != 0) || (posy != 0 && posz != 0)) {
        multiplier = oneoversqrttwo;
    }
    
    pos += speed * glm::vec3(posx,posy,posz)  * multiplier;
    std::cout <<  glm::length(speed * glm::vec3(posx,posy,posz)  * multiplier)<< std::endl;
    posx = 0;
    posy = 0;
    posz = 0;
}
