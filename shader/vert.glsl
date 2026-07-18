#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normals;

out vec3 normal;
out vec3 frag_pos;

uniform mat4 transform;
uniform mat4 camera_matrix;

void main() {
    vec4 world_pos = transform * vec4(pos, 1.0);

    frag_pos = world_pos.xyz;
    normal = mat3(transpose(inverse(transform))) * normals;


    gl_Position = camera_matrix * world_pos;
}
