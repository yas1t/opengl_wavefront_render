#pragma once

#include "glad/glad.h"
#include "vertex.hpp"
#include <iostream>

class vertex_buffer  {
private:

    unsigned int id;

public:

    void setup(size_t size, const std::vector<vertex>& data);
    void bind();
    void destroy();

};


class index_buffer  {
private:

    unsigned int id;

public:

    void setup(size_t size, const std::vector<unsigned int>& data);
    void bind();
    void destroy();

};
