#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Player
{
public:
	float angle = 0.0;
	float lx = 0.0f, lz = -1.0f;
	float x = 0.0f, z = 5.0f;

	void refreshLook();
};

