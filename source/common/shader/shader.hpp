#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace our
{

    class ShaderProgram
    {

    private:
        // Shader Program Handle
        GLuint program;

    public:
        void create();
        void destroy();

        ShaderProgram() { program = 0; }
        ~ShaderProgram() { destroy(); }

        bool attach(const std::string &filename, GLenum type) const;

        bool link() const;

        void use()
        {
            // TODO: call opengl to use the program identified by this->program
            // installs the program object specified by program as part of current rendering state.
            glUseProgram(this->program);
        }

        GLuint getUniformLocation(const std::string &name)
        {
            // TODO: call opengl to get the uniform location for the uniform defined by name from this->program
            return glGetUniformLocation(
                this->program, // Specifies the program object to be queried.
                name.c_str()   // the name of the uniform variable whose location is to be queried.
            );
        }

        void set(const std::string &uniform, GLfloat value)
        {
            // TODO: call opengl to set the value to the uniform defined by name

            //==// Set Val To The Uniform That Specified By Location
            glUniform1f(getUniformLocation(uniform), value);
        }

        void set(const std::string &uniform, glm::vec2 value)
        {
            // TODO: call opengl to set the value to the uniform defined by name

            //==// Set Val To Uniform Specified By Its Location
            glUniform2f(getUniformLocation(uniform), value.x, value.y);
        }

        void set(const std::string &uniform, glm::vec3 value)
        {
            // TODO: call opengl to set the value to the uniform defined by name

            //==// Set Val To Uniform Specified By Its Location
            glUniform3f(getUniformLocation(uniform), value.x, value.y, value.z);
        }

        void set(const std::string &uniform, glm::vec4 value)
        {
            // TODO: call opengl to set the value to the uniform defined by name

            //==// Set Val To Uniform Specified By Its Location
            glUniform4f(getUniformLocation(uniform), value.x, value.y, value.z, value.w);
        }

        // TODO: Delete the copy constructor and assignment operator
        ShaderProgram(const ShaderProgram &) = delete;
        ShaderProgram &operator=(const ShaderProgram &) = delete;

        // Question: Why do we do this? Hint: Look at the deconstructor
        /**
         * Answer:
         * The compiler-generated copy constructor is wrong; it copies the OpenGL object name, not the OpenGL object itself.
         * This leaves two C++ objects which each intend to destroy the same OpenGL object.
         * Ideally, leacing copy constructor will allow copy of the OpenGL object's data into a new OpenGL object.
         * This would leave each C++ object with its own unique OpenGL object.
         *  However, copying an OpenGL object's data to a new object is incredibly expensive;
         * it is also essentially impossible to do. So instead, we should forbid copying of OpenGL wrapper objects.
         * Resources like shaderprograms shouldn't be copyable, but instead moveable.
         */
    };

}

#endif