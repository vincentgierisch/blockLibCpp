#ifndef LOAD_SHADER_HPP
#define LOAD_SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <vector>
#include "../utils/helper.h"

class Shader {
	public:
		// Reference ID of the shader program
		GLuint Id;
		Shader(const char* vertexFile, const char* fragmentFile);

		// Activate the shader program
		void Activate();
		// Delete the shader program
		void Delete();
};

#endif


