#pragma comment(lib, "freeglut.lib")
#pragma once
#include <iostream>
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static const GLfloat lightPos[] = { 100.0f, 200.0f, 0.0f, 1.0f };
static const GLfloat lightAmb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
static const GLfloat lightDif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
static const GLfloat lightSpc[] = { 1.0f, 1.0f, 1.0f, 1.0f };
static GLfloat lookA;
static GLfloat angle;

class Engine
{
private:
	int fps;

	EngineConfiguration conf;
	Engine(EngineConfiguration engineConfiguration);
public:
	static Engine* engine;
	static Engine* getInstance();


	void clearScreen();
	void start();
	static void loop(void);
	void init(int argc, char* argv[]);
	void exit();
	static void onScreenSizeChange(GLsizei w, GLsizei h);
};

