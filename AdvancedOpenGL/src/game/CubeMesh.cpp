#include "CubeMesh.h"
#include "../engine/Log.h"

void CubeMesh::load() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    static const GLfloat vertexPositions[] =
  {
          -0.25f,  0.25f, -0.25f,
          -0.25f, -0.25f, -0.25f,
            0.25f, -0.25f, -0.25f,

            0.25f, -0.25f, -0.25f,
            0.25f,  0.25f, -0.25f,
          -0.25f,  0.25f, -0.25f,

            0.25f, -0.25f, -0.25f,
            0.25f, -0.25f,  0.25f,
            0.25f,  0.25f, -0.25f,

            0.25f, -0.25f,  0.25f,
            0.25f,  0.25f,  0.25f,
            0.25f,  0.25f, -0.25f,

            0.25f, -0.25f,  0.25f,
          -0.25f, -0.25f,  0.25f,
            0.25f,  0.25f,  0.25f,

          -0.25f, -0.25f,  0.25f,
          -0.25f,  0.25f,  0.25f,
            0.25f,  0.25f,  0.25f,

          -0.25f, -0.25f,  0.25f,
          -0.25f, -0.25f, -0.25f,
          -0.25f,  0.25f,  0.25f,

          -0.25f, -0.25f, -0.25f,
          -0.25f,  0.25f, -0.25f,
          -0.25f,  0.25f,  0.25f,

          -0.25f, -0.25f,  0.25f,
            0.25f, -0.25f,  0.25f,
            0.25f, -0.25f, -0.25f,

            0.25f, -0.25f, -0.25f,
          -0.25f, -0.25f, -0.25f,
          -0.25f, -0.25f,  0.25f,

          -0.25f,  0.25f, -0.25f,
            0.25f,  0.25f, -0.25f,
            0.25f,  0.25f,  0.25f,

            0.25f,  0.25f,  0.25f,
          -0.25f,  0.25f,  0.25f,
          -0.25f,  0.25f, -0.25f
  };

  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);

  LOG(Info) << "vertexPositions size " << sizeof(vertexPositions);

}

void CubeMesh::draw() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void CubeMesh::drawPatches() {
    glBindVertexArray(vao);
    glDrawArrays(GL_PATCHES, 0, 36);
    glBindVertexArray(0);
}

void CubeMesh::clean() {
  glDeleteVertexArrays(1, &vao);
}