#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

#include "../../lib/include/stb/stb_image.hpp"

#include "shader.h"

class Texture {
	public:
		GLuint Id;
		GLenum type;

		Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
		// Assigns a texture unit to a texture
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		// Binds a texture
		void Bind();
		// Unbinds a texture
		void Unbind();
		// Deletes a texture
		void Delete();
};
#endif
