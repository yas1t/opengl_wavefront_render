#pragma once

#include <iostream>
#include "glad/glad.h"

class vertex_array {
private:
    unsigned int id;
public:
    vertex_array();
    void add_attrib(unsigned int loc, int size, int type, int norm, size_t stride, void* offset);
    void bind();

};
