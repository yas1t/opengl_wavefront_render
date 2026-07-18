#include "window.hpp"
#include "shader.hpp"
#include "camera.hpp"
#include "mesh.hpp"
#include "vertex.hpp"

#include <iostream>

#include "fast_obj.h"

#define SCRW 1280
#define SCRH 720

int main(void) {

    GLFWwindow *window = window_init(SCRW, SCRH, "My beautiful Project", 3, 3);

    program shader_p("shader/vert.glsl", "shader/frag.glsl");

    mesh_data cube_mesh = load_obj("assets/gato/cat_triangulated.obj");
    mesh block(shader_p.p_id, &cube_mesh);

    camera cam(shader_p.p_id, (float)SCRW / (float)SCRH);

    block.scale(glm::vec3(0.1, 0.1, 0.1));

    float deltatime = 0.0f;
    float lastframe = 0.0f; 
    float currentframe = 0.0f; //optimized code by 0.00001% 

    while(!glfwWindowShouldClose(window)) {
        currentframe = glfwGetTime();
        deltatime = currentframe - lastframe;
        lastframe = currentframe;

        cam.speed *= deltatime ;

        block.translate(glm::vec3(0.0f, 3 * glm::sin(glm::radians(glfwGetTime()*200)), 0.0f), deltatime); // magic number fest
        block.rotate(50.0f, deltatime, glm::vec3(0.0f, 1.0f, 0.0f));


        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader_p.use();


        cam.run();
        cam.move(&window);


        block.update(deltatime);
        block.draw();


        glfwSwapBuffers(window);
    }


    return 0;
}
