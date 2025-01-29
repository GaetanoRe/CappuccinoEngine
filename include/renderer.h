#pragma once
#include <string>
#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Renderer{
    public:
        Renderer();
        ~Renderer();

        void init();
        void render();
        void setTexture(const std::string & path);
    
    private:
        GLuint vao, vbo, ebo;
        GLuint shaderProg;
        GLuint texture;

        GLuint compileShader(const std::string & path);
        GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader);


};

