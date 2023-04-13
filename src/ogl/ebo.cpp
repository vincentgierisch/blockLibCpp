#include "ebo.h"

EBO::EBO(std::vector<GLuint>& indices) {
	glGenBuffers(1, &(this->Id));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->Id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void EBO::addIndices(std::vector<GLuint>& indices) {
	glGenBuffers(1, &(this->Id));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->Id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->Id);
}

void EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
	glDeleteBuffers(1, &(this->Id));
}
