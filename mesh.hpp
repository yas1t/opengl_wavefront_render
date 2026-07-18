#pragma once

#include <iostream>
#include <cstddef>

#include "glad/glad.h"
#include "vertex.hpp"
#include "vertex_buffer.hpp"
#include "vertex_array.hpp"


class mesh {
private:
    vertex_array  vao;
    vertex_buffer vbo;
    index_buffer ibo;

    unsigned int index_count;
    unsigned int vertex_count;

    unsigned int u_loc;
    unsigned int light_loc;
    glm::mat4 model = glm::mat4(1.0f);

public:
    mesh_data meshdata;

    glm::vec3 pos;

    mesh(unsigned int program, mesh_data *data);

    bool is_light;


    void draw();
    void update(float dt);
    void rotate(float angle, float dt, glm::vec3 axis);
    void scale(glm::vec3 value);
    void translate(glm::vec3 vec, float dt);

};
