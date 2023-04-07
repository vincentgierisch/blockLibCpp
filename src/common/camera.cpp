#include "camera.h"


void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader) {
	// initializa matrices
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(this->_position, this->_position + this->_orientation, this->_up);

	projection = glm::perspective(glm::radians(FOVdeg), (float)this->_width / this->_height, nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(shader.Id, "proj"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shader.Id, "view"), 1, GL_FALSE, glm::value_ptr(view));
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

		double mouseX, mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = this->_sensitivity * (float)(mouseY - (this->_height/2))/this->_height;
		float rotY = this->_sensitivity * (float)(mouseX - (this->_width/2))/this->_width;
		
		glm::vec3 newOrientation = glm::rotate(this->_orientation, glm::radians(-rotX), glm::normalize(glm::cross(this->_orientation, this->_up)));

		if (abs(glm::angle(newOrientation, this->_up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {
			this->_orientation = newOrientation;
		}

		this->_orientation = glm::rotate(this->_orientation, glm::radians(-rotY), this->_up);
		glfwSetCursorPos(window, (this->_width/2), (this->_height/2));
	} else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		this->_firstClick = true;
	}
	
}
