#ifndef MESH_H
#define MESH_H

#include <vector>
#include <GL/glew.h>
#include "ogl/vbo.h"

struct Mesh {
	std::vector<Vertex> vertexPositions;
	//std::vector<GLfloat> textureCoords;
	std::vector<GLuint> indices;
};
#endif
