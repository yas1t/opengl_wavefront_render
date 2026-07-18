#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <string>

typedef struct {
    glm::vec3 pos;
    glm::vec3 normals;
    glm::vec2 tex_coords;
} vertex;

typedef struct mesh_data {
    std::vector<vertex> v;
    std::vector<unsigned int> indices;
} mesh_data;

mesh_data load_obj(std::string filepath);
