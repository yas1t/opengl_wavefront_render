#include "../shader.hpp"
#include <glm/gtc/type_ptr.hpp>

std::string read_src(std::string filename) {
    std::ifstream file(filename);
    if (file.fail()) {
        std::cerr << "Failed to open file: " << filename << '\n';
        return NULL;
    }

    std::string buffer;
    std::string src;
    while(std::getline(file, buffer)) {
        src.append(buffer);
        src.push_back('\n');
    }

    return src;
}

program::program(std::string v_filename, std::string f_filename) {
    v_id = glCreateShader(GL_VERTEX_SHADER);
    f_id = glCreateShader(GL_FRAGMENT_SHADER);

    std::string v_src = read_src(v_filename);
    std::string f_src = read_src(f_filename);

    const char *v_src_c = v_src.c_str();
    const char *f_src_c = f_src.c_str();

    glShaderSource(v_id, 1, &v_src_c, NULL);
    glShaderSource(f_id, 1, &f_src_c, NULL);

    p_id = glCreateProgram();

    glCompileShader(v_id);
    glCompileShader(f_id);

    int success;
    char info[512];

    glGetShaderiv(v_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(v_id, 512, NULL, info);
        std::cout << "Vertex shader error:\n" << info << '\n';
    }

    glGetShaderiv(f_id, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(f_id, 512, NULL, info);
        std::cout << "Fragment shader error:\n" << info << '\n';
    }

    glAttachShader(p_id, v_id);
    glAttachShader(p_id, f_id);

    glLinkProgram(p_id);

    glDeleteShader(v_id);
    glDeleteShader(f_id);

}
void program::use() {
    glUseProgram(p_id);
}

void program::set_vec3(std::string name, glm::vec3 value) {
    glUniform3fv(glGetUniformLocation(p_id, name.c_str()), 1, glm::value_ptr(value));
}
void program::set_mat4(std::string name, glm::mat4 value) {
    glUniformMatrix4fv(glGetUniformLocation(p_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}




