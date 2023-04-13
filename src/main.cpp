#define STB_IMAGE_IMPLEMENTATION
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>

//#include <stb/stb_image.hpp>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ogl/shader.h"
#include "ogl/vbo.h"
#include "ogl/vao.h"
#include "ogl/ebo.h"
#include "ogl/texture.h"
#include "common/camera.h"

#include "world/chunk.h"
#include "world/generator/flatLandGenerator.h"
#include "renderer/chunkRenderer.h"

#define WIDTH 800
#define HEIGHT 800


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

		// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 	
	
	Camera camera(WIDTH, HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));
	ChunkRenderer cRenderer;
	FlatLandGenerator flGenerator;
	Chunk testChunk;
	flGenerator.generateTerrain(testChunk);
	testChunk.getMesh().activate();

	std::cout << "Amount of indices: " << testChunk.getMesh().getMesh().indices.size() << std::endl;
	
	// render loop
	do {
		// specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// clear the back buffer and assign the new colr to it
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
	
		camera.updateInputs(window);
			
		cRenderer.draw(testChunk.getMesh(), camera);	
		
		// swap back buffer with the front buffer
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	glfwTerminate();
	return 0;
}
