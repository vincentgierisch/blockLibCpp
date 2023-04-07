#include "vao.h"


VAO::VAO() {
	glGenVertexArrays(1, &(this->Id));
}

void VAO::LinkAttrib(VBO& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	vbo.Bind();
	glVertexAttribPointer(
		layout, // attribute 0 (no paricular reason, however must match layout in shader)
		numComponents, // size
		type, // type 
		GL_FALSE, // normalized 
		stride, // stride 
		offset // array buffer offset
	);
	glEnableVertexAttribArray(layout);
	vbo.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(this->Id);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &(this->Id));
}
