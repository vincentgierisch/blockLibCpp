#include "shader.h"

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	// read files and store the strings
	std::string vertexCode = Helper::readFileContents(vertexFile); 
	std::string fragmentCode = Helper::readFileContents(fragmentFile); 
	const char* vertexSource = vertexCode.c_str(); 
	const char* fragmentSource = fragmentCode.c_str();
	
	// create vertex shader object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// attach vertex shader source to the vertex shader object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// compile vertex shader
	glCompileShader(vertexShader);
	
	// see comments above
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	
	this->Id = glCreateProgram();
	glAttachShader(this->Id, vertexShader);
	glAttachShader(this->Id, fragmentShader);

	// link shaders
	glLinkProgram(this->Id);

	// Delete shaders (they are already loaded/copied to the program)
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);	
}

void Shader::Activate() {
	glUseProgram(this->Id);
}

void Shader::Delete() {
	glDeleteProgram(this->Id);
}
