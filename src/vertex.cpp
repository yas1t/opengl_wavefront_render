#include "../vertex.hpp"
#include "../fast_obj.h"

#include <iostream>


mesh_data load_obj(std::string filepath) {
    fastObjMesh *mesh = fast_obj_read(filepath.c_str());

    std::vector<vertex> verts;
    std::vector<unsigned int> inds;

    mesh_data data;

    for(unsigned int i = 0; i < mesh->index_count; i++) {
        vertex buffer = {};
        fastObjIndex ind = mesh->indices[i];

        buffer.pos.x   = mesh->positions[3 * ind.p + 0];
        buffer.pos.y   = mesh->positions[3 * ind.p + 1];
        buffer.pos.z   = mesh->positions[3 * ind.p + 2];

        if(ind.n != 0) {
        buffer.normals.x = mesh->normals[3 * ind.n + 0];
        buffer.normals.y = mesh->normals[3 * ind.n + 1];
        buffer.normals.z = mesh->normals[3 * ind.n + 2];
        }

        verts.push_back(buffer);
        inds.push_back(i);
    }


    data.v = verts;
    data.indices = inds;
    std::cout <<"mesh face count: "<< mesh->face_count << '\n';

    for (int i = 0; i < 10; i++)
        std::cout << (int)mesh->face_vertices[i] << ' ';

    return data;
}
