#include "vbo.h"

VBO::VBO(std::vector<Vertex>& vertices) {
	glGenBuffers(1, &(this->Id));
	glBindBuffer(GL_ARRAY_BUFFER, this->Id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VBO::addVertices(std::vector<Vertex>& vertices) {
	glGenBuffers(1, &(this->Id));
	glBindBuffer(GL_ARRAY_BUFFER, this->Id);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VBO::Bind() {
	glBindBuffer(GL_ARRAY_BUFFER, this->Id);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	glDeleteBuffers(1, &(this->Id));
}
