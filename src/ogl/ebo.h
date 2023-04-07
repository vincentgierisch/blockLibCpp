#ifndef EBO_H
#define EBO_H

#include <GL/glew.h>

class EBO {
	public:
		GLuint Id;
		EBO(GLuint* indices, GLsizeiptr size);
		
		void Bind();
		void Unbind();
		void Delete();
};
#endif
