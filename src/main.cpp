#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "loadShader.hpp"

int main() {
	
	if(!glfwInit()) {
		const char* description;
		int code = glfwGetError(&description);
		std::cout << "Failed to initializeGLFW: " << description << std::endl;
		return 1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	

	// Create Window
	GLFWwindow* window = glfwCreateWindow(600, 300, "RisiGame", NULL, NULL);
	if(window == NULL) {
		std::cout << "Failed to open GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) {
	  /* Problem: glewInit failed, something is seriously wrong. */
		std::cerr << "Error while init glew: " << glewGetErrorString(err) << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// init background color
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	GLuint vertexArrayId;
	glGenVertexArrays(1, &vertexArrayId);
	glBindVertexArray(vertexArrayId);

	GLuint programId = LoadShaders("shaders/SimpleVertexShader.vertexshader", "shaders/SimpleFragmentShader.fragment");


	static const GLfloat gVertexBufferData[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f
	};

	// create vertex buffer
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	// Give our vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(gVertexBufferData), gVertexBufferData, GL_STATIC_DRAW);
	
	// render loop
	do {
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(programId);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(
			0,			// attribute 0 (no paricular reason, however must match layout in shader)
			3,			// size
			GL_FLOAT, 	// type
			GL_FALSE,	// normalized?
			0,			// stride
			(void*)0	// array buffer offset
		);
		
		// Draw the triangle
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		
		// swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &vertexBuffer);
	glDeleteVertexArrays(1, &vertexArrayId);
	glDeleteProgram(programId);
	
	glfwTerminate();
	return 0;
}
