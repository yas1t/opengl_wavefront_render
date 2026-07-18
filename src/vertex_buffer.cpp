#include "../vertex_buffer.hpp"

void vertex_buffer::setup(size_t size, const std::vector<vertex>& data) {

    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);

}

void vertex_buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void index_buffer::setup(size_t size, const std::vector<unsigned int>& data) {
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
}
void index_buffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
