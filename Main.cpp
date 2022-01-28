#pragma comment(lib, "freeglut.lib")
#pragma once
#include <iostream>

#include <windows.h>
#include <gl\gl.h>
#include <gl\freeglut.h>
#include "Engine.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main(int argc, char* argv[]) {
	Engine* engine = Engine::getInstance();
	engine->init(argc, argv);
	engine->start();
}
