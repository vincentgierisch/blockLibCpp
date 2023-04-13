#ifndef EBO_H
#define EBO_H

#include <GL/glew.h>
#include <vector>

class EBO {
	public:
		GLuint Id;
		EBO(){};
		EBO(std::vector<GLuint>& indices);
		
		void addIndices(std::vector<GLuint>& indices);
		void Bind();
		void Unbind();
		void Delete();
};
#endif
