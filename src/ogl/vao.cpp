#include "vao.h"


VAO::VAO() {
	glGenVertexArrays(1, &(this->Id));
}

void VAO::LinkVBO(VBO& vbo, GLuint layout) {
	vbo.Bind();
	glVertexAttribPointer(
		layout, // attribute 0 (no paricular reason, however must match layout in shader)
		3, // size
		GL_FLOAT, // type 
		GL_FALSE, // normalized 
		0, // stride 
		(void*)0 // array buffer offset
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
