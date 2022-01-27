#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Point3D.h"
#include <glm/gtx/rotate_vector.hpp>

class Player
{
public:
	glm::vec3 position;
	glm::vec3 lookingAt;
	glm::vec3 upVec;
	
	bool firstMouse = true;
	float lastX, lastY, yaw, pitch;

	float sensitivity = 1.0f;

	void move(glm::vec3 v);
	void rotate();
	void defaultPos();
	glm::mat4 Look();
};

