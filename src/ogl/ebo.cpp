#include "ebo.h"

EBO::EBO(GLuint* indices, GLsizeiptr size) {
	glGenBuffers(1, &(this->Id));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->Id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
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
