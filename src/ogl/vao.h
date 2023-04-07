#ifndef VAO_H
#define VAO_H

#include "vbo.h"
#include <GL/glew.h>

class VAO {
	public:
		GLuint Id;
		VAO();

		void LinkAttrib(VBO& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
		void Bind();
		void Unbind();
		void Delete();	
};
#endif
