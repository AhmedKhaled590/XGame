#pragma once

#include <glad/gl.h>
#include "vertex.hpp"

namespace our
{

#define ATTRIB_LOC_POSITION 0
#define ATTRIB_LOC_COLOR 1
#define ATTRIB_LOC_TEXCOORD 2
#define ATTRIB_LOC_NORMAL 3

    class Mesh
    {
        // Here, we store the object names of the 3 main components of a mesh:
        // A vertex array object, A vertex buffer and an element buffer
        unsigned int VBO, EBO;
        unsigned int VAO;
        // We need to remember the number of elements that will be draw by glDrawElements
        GLsizei elementCount;

    public:
        // The constructor takes two vectors:
        // - vertices which contain the vertex data.
        // - elements which contain the indices of the vertices out of which each rectangle will be constructed.
        // The mesh class does not keep a these data on the RAM. Instead, it should create
        // a vertex buffer to store the vertex data on the VRAM,
        // an element buffer to store the element data on the VRAM,
        // a vertex array object to define how to read the vertex & element buffer during rendering
        Mesh(const std::vector<Vertex> &vertices, const std::vector<unsigned int> &elements)
        {
            // TODO: (Req 1) Write this function
            elementCount = elements.size();

            // Create a vertex array object (VAO)
            glGenVertexArrays(1, &VAO);
            // Bind the VAO
            glBindVertexArray(VAO);

            // Create a vertex buffer object (VBO)
            glGenBuffers(1, &VBO);
            // Bind the VBO
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            // Copy the vertex data to the VBO
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

            // Create an element buffer object (EBO)
            glGenBuffers(1, &EBO);
            // Bind the EBO
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            // Copy the element data to the EBO
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(unsigned int), &elements[0], GL_STATIC_DRAW);

            // Tell OpenGL how to interpret the vertex data
            glEnableVertexAttribArray(ATTRIB_LOC_POSITION);
            glVertexAttribPointer(ATTRIB_LOC_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);

            glEnableVertexAttribArray(ATTRIB_LOC_COLOR);
            glVertexAttribPointer(ATTRIB_LOC_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)(3 * sizeof(float)));

            glEnableVertexAttribArray(ATTRIB_LOC_TEXCOORD);
            glVertexAttribPointer(ATTRIB_LOC_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(3 * sizeof(float) + 4 * sizeof(glm::uint8)));

            glEnableVertexAttribArray(ATTRIB_LOC_NORMAL);
            glVertexAttribPointer(ATTRIB_LOC_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(3 * sizeof(float) + 4 * sizeof(glm::uint8) + 2 * sizeof(float)));

            // Unbind the VAO
            glBindVertexArray(0);
            // Unbind the VBO
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            // Unbind the EBO
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            // remember to store the number of elements in "elementCount" since you will need it for drawing
            // For the attribute locations, use the constants defined above: ATTRIB_LOC_POSITION, ATTRIB_LOC_COLOR, etc
        }

        // this function should render the mesh
        void draw()
        {
            // TODO: (Req 1) Write this function
            // Bind the VAO
            glBindVertexArray(VAO);

            // bind the VBO
            glBindBuffer(GL_ARRAY_BUFFER, VBO);

            // bind the EBO
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            // Draw the mesh
            glDrawElements(GL_TRIANGLES, elementCount, GL_UNSIGNED_INT, 0);
        }

        // this function should delete the vertex & element buffers and the vertex array object
        ~Mesh()
        {
            // TODO: (Req 1) Write this function
            glDeleteBuffers(1, &VBO);
            glDeleteBuffers(1, &EBO);
            glDeleteVertexArrays(1, &VAO);
        }

        Mesh(Mesh const &) = delete;
        Mesh &operator=(Mesh const &) = delete;
    };

}