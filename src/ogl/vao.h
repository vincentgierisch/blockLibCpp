#ifndef VAO_H
#define VAO_H

#include "vbo.h"
#include <GL/glew.h>

class VAO {
	public:
		GLuint Id;
		VAO();

		void LinkVBO(VBO& vbo, GLuint Layout);
		void Bind();
		void Unbind();
		void Delete();	
};
#endif
