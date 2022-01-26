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
#include "PrimitivePoint.h"
#include "PrimitiveLine.h"
#include "PrimitiveTriangle.h"
#include "PrimitiveQuad.h"
#include "Player.h"
#include "PrimitiveCube.h"
#include "BitmapHandler.h"
#include "TexturedCube.h"
#include "Anim8torSupport.h"

class Engine
{
private:
	int fps;

	EngineConfiguration conf;
	Engine(EngineConfiguration engineConfiguration);
public:
	static Engine* engine;
	static Engine* getInstance();
	static Player myPlayer;
	


	void start();
	static void loop(void);
	void init(int argc, char* argv[]);
	void exit();
	static void onScreenSizeChange(GLsizei w, GLsizei h);
	static void OnIdle();
	static void processSpecialKeys(int key, int xx, int yy);

};

