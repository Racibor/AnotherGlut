#pragma comment(lib, "freeglut.lib")
#pragma once
#include <iostream>
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>

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
};

