#include "../vertex_array.hpp"

vertex_array::vertex_array() {
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
}
void vertex_array::add_attrib(unsigned int loc, int size, int type, int norm, size_t stride, void* offset) {
    glVertexAttribPointer(loc, size, type, norm, stride, (void*)offset);
    glEnableVertexAttribArray(loc);
}
void vertex_array::bind() {
    glBindVertexArray(id);
}
