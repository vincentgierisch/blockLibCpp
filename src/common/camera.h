#ifndef CAMERA_H
#define CAMERA_H

#include <math.h>

#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include <GLFW/glfw3.h>

#include "../ogl/shader.h"

class Camera {
	private:
		glm::vec3 _position;
		glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
		
		// prevent the camera from jumping around
		bool _firstClick = true;
		
		int _width, _height;

		// adjust the speed of the camera and it*s sensitivity when looking around
		float _speed = 0.1f;
		float _sensitivity = 100.0f;
	public:
		Camera(int width, int height, glm::vec3 position) : _width(width), _height(height), _position(position){};
		void updateMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader);
		void updateInputs(GLFWwindow* window);
			
};
#endif
