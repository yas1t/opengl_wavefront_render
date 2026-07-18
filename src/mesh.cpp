#include "../mesh.hpp"


mesh::mesh(unsigned int program, mesh_data *data) {
    vao.bind();
    vbo.setup(data->v.size()*sizeof(vertex), data->v);

    vao.add_attrib(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, pos));
    vao.add_attrib(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)offsetof(vertex, normals));

    ibo.setup(data->indices.size()*sizeof(unsigned int), data->indices);



    index_count  = data->indices.size();
    vertex_count = data->v.size();

    u_loc = glGetUniformLocation(program, "transform");

    model = glm::mat4(1.0f);


}
void mesh::rotate(float angle, float dt, glm::vec3 axis) {
    model = glm::rotate(model, glm::radians(angle)*dt, axis);

}
void mesh::translate(glm::vec3 vec, float dt) {
    model = glm::translate(model, vec * dt);
}

void mesh::scale(glm::vec3 value) {
    model = glm::scale(model, value);
}
void mesh::update(float dt) {
    glUniformMatrix4fv(u_loc, 1, GL_FALSE, glm::value_ptr(model));
}

void mesh::draw() {
    vao.bind();
    ibo.bind();
    //glDrawElements(GL_TRIANGLES, index_count, GL_UNSIGNED_INT, nullptr);
    glDrawArrays(GL_TRIANGLES, 0, vertex_count);
}
