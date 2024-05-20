#ifndef CAMERA_H
#define CAMERA_H

#define GLM_ENABLE_EXPERIMENTAL
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
		glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, 1.0f);
		glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
		
		glm::vec2 _rotation = glm::vec2(0.0f, 0.0f);

		glm::mat4 cameraMatrix = glm::mat4(1.0f);

		// prevent the camera from jumping around
		bool _firstClick = true;
		
		int _width, _height;
		std::pair<double, double> _lastMousePosition;
		// adjust the speed of the camera and it*s sensitivity when looking around
		float _speed = 0.1f;
		float _sensitivity = 100.0f;
	public:
		Camera(int width, int height, glm::vec3 position) : _width(width), _height(height), _position(position){
			this->_lastMousePosition = std::make_pair(width/2, height/2);
		};
		void updateMatrix(float FOVdeg, float nearPlane, float farPlane);
		void exportMatrix(Shader& shader);
		void updateInputs(GLFWwindow* window);
};
#endif
