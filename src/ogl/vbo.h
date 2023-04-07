#ifndef VBO_H
#define VBO_H

#include <GL/glew.h>

class VBO {
	public:
		GLuint Id;
		VBO(GLfloat* vertices, GLsizeiptr size);
		
		void Bind();
		void Unbind();
		void Delete();
};
#endif
