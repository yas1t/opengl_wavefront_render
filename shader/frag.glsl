#version 330 core

out vec4 color;
in vec3 normal;

void main()
{
    color = vec4(normalize(normal) * 0.5 + 0.5, 1.0);
}
