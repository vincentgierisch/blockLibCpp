#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ogl/shader.h"
#include "ogl/vbo.h"
#include "ogl/vao.h"
#include "ogl/ebo.h"

#define WIDTH 800
#define HEIGHT 800

GLfloat vertices[] = {
	// Coordinates										/ COLOR
	   -0.5f, 	-0.5f * float(sqrt(3)) / 3, 	0.0f,	0.8f, 0.3f, 0.02f, // lower left corner
	   0.5f, 	-0.5f * float(sqrt(3)) / 3, 	0.0f, 	0.8f, 0.3f, 0.02f,// lower right corner
	   0.0f, 	0.5f * float(sqrt(3)) * 2 / 3, 	0.0f, 	1.0f, 0.0f, 0.02f,// upper corner
	   -0.25f, 	0.5f * float(sqrt(3)) / 6, 		0.0f, 	0.9f, 0.45f, 0.17f,// inner left
	   0.25f, 	0.5f * float(sqrt(3)) / 6, 		0.0f, 	0.9f, 0.45f, 0.17f,// inner right
	   0.0f, 	-0.5f * float(sqrt(3)) / 3, 	0.0f, 	0.8f, 0.3f, 0.02f,// inner down
};

GLuint indices[] = {
	0, 3, 5, // lower left triangle
	3, 2, 4, // lower right triangle
	5, 4, 1 // upper triangle
};

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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "RisiGame", NULL, NULL);
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
	glViewport(0, 0, WIDTH, HEIGHT);
	
	Shader shaderProgram("shaders/SimpleShader.vert", "shaders/SimpleShader.frag");

	// create reference containers for the Vertex Array Object and the Vertex Buffer Object
	VAO VAO1;
	// make the VAO the current Vertex Array Object by binding it
	VAO1.Bind();


	// Projection matrix -> 45° Field of View, 4:3 ratio, display range : 0.1 unti <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	// camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	glm::mat4 Model = glm::mat4(1.0f);

	GLuint projMatrixId = glGetUniformLocation(shaderProgram.Id, "proj");
	GLuint viewMatrixId = glGetUniformLocation(shaderProgram.Id, "view");
	GLuint modelMatrixId = glGetUniformLocation(shaderProgram.Id, "model");

	// create vertex buffer
	VBO VBO1(vertices, sizeof(vertices));
	//Generate Element Buffer Object and links it to the indices
	EBO EBO1(indices, sizeof(indices));

	// link vbo to vao
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6*sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6*sizeof(float), (void*)(3 * sizeof(float)));
	
	// unbind all to prevent accidentally modification
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();	
		
	// render loop
	do {

		// specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clear the back buffer and assign the new colr to it
		glClear(GL_COLOR_BUFFER_BIT);
		
		shaderProgram.Activate();	
		
		glUniformMatrix4fv(projMatrixId, 1, GL_FALSE, glm::value_ptr(Projection));
		glUniformMatrix4fv(viewMatrixId, 1, GL_FALSE, glm::value_ptr(View));
		glUniformMatrix4fv(modelMatrixId, 1, GL_FALSE, glm::value_ptr(Model));
			
		VAO1.Bind();
		
		// Draw the primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		
		// swap back buffer with the front buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	// Delete all objects
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	
	glfwTerminate();
	return 0;
}
