#include "../camera.hpp"

camera::camera(unsigned int program, float asp_rat) {
    fov = 90.0f;
    aspect_ratio = asp_rat;

    pos = glm::vec3(0.0f, 1.0f, 5.0f);
    front = glm::vec3(0.0f, 0.0f, -1.0f);

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
    if(glfwGetKey(*window, GLFW_KEY_W) == GLFW_PRESS) {
        pos += speed * front;
    }
    if(glfwGetKey(*window, GLFW_KEY_S) == GLFW_PRESS) {
        pos -= speed * front;
    }
    if(glfwGetKey(*window, GLFW_KEY_UP) == GLFW_PRESS) {
        pos.y += speed;
    }
    if(glfwGetKey(*window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        pos.y -= speed;
    }
}
