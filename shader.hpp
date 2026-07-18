#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>
#include <fstream>

std::string read_src(std::string filename);

class program {
public:
    unsigned int p_id;

    program(std::string v_filename, std::string f_filename);
    void use();
    void set_vec3(std::string name, glm::vec3 value);
    void set_mat4(std::string name, glm::mat4 value);
private:
    unsigned int v_id;
    unsigned int f_id;

};
