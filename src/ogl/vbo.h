#ifndef VBO_H
#define VBO_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex
{
	glm::vec3 position;
	//glm::vec2 texUV;
	glm::vec3 color;
};

class VBO {
	public:
		GLuint Id;
		VBO(){};
		VBO(std::vector<Vertex>& vertices);
		
		void addVertices(std::vector<Vertex>& vertices);
		void Bind();
		void Unbind();
		void Delete();
};
#endif
