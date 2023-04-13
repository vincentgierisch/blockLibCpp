#include "camera.h"


void Camera::exportMatrix(Shader& shader) {
	glUniformMatrix4fv(glGetUniformLocation(shader.Id, "camera"), 1, GL_FALSE, glm::value_ptr(this->cameraMatrix));
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	// initializa matrices
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	//view = glm::lookAt(this->_position, this->_position + this->_orientation, this->_up);

	// view = glm::rotate(view, glm::radians(this->_rotation.x), glm::normalize(glm::cross(this->_orientation, this->_up)));
	// view = glm::rotate(view, glm::radians(this->_rotation.y), glm::normalize(glm::cross(this->_orientation, this->_up)));
	//view = glm::rotate(view, glm::radians(this->_rotation.z), {0, 0, 1});

	// this->_orientation = glm::rotateX(this->_orientation, this->_rotation.x*0.01745f);
	// this->_orientation = glm::rotateY(this->_orientation, this->_rotation.y*0.01745f);

	// this->_orientation.x = this->_orientation.x * cos(this->_rotation.x) - this->_orientation.y * sin(this->_rotation.x);

	//this->_orientation = glm::rotate(this->_orientation, glm::radians(this->_rotation.x), this->_up);
	
	this->_orientation = glm::rotate(this->_orientation, glm::radians(-this->_rotation.x), glm::normalize(glm::cross(this->_orientation, this->_up)));
	this->_orientation = glm::rotate(this->_orientation, glm::radians(-this->_rotation.y), this->_up);	

	view = glm::lookAt(this->_position, this->_position + this->_orientation, this->_up);

	projection = glm::perspective(glm::radians(FOVdeg), (float)this->_width / this->_height, nearPlane, farPlane);
	this->cameraMatrix = projection * view;
}

void Camera::updateInputs(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		this->_position += this->_speed * this->_orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		this->_position += this->_speed * -glm::normalize(glm::cross(this->_orientation, this->_up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		this->_position += this->_speed * -this->_orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		this->_position += this->_speed * glm::normalize(glm::cross(this->_orientation, this->_up));
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		this->_position += this->_speed * this->_up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		this->_position += this->_speed * -this->_up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		this->_speed = 0.4f;
	}else if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		this->_speed = 0.1f;
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		
		if (this->_firstClick) {
			glfwSetCursorPos(window, (this->_width/2), (this->_height/2));
			this->_firstClick = false;
		}

		double mouseX, mouseY, changeX, changeY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		changeX = mouseX - this->_lastMousePosition.first;
		changeY = mouseY - this->_lastMousePosition.second;

		this->_lastMousePosition = std::make_pair(mouseX, mouseY);

		this->_rotation.y = this->_sensitivity * (float)(mouseX - (this->_height / 2)) / this->_height;
		this->_rotation.x = this->_sensitivity * (float)(mouseY - (this->_width / 2)) / this->_width;
/*
		float const BOUND = 89.f;

		if (this->_rotation.x > BOUND)
			this->_rotation.x = BOUND;
		else if (this->_rotation.x < -BOUND)
			this->_rotation.x = -BOUND;
		if (this->_rotation.y > 360)
			this->_rotation.y = 0;
		else if (this->_rotation.y < 0)
			this->_rotation.y = 360;
*/
		glfwSetCursorPos(window, (this->_width/2), (this->_height/2));
	} else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		this->_firstClick = true;
	}
	
}
