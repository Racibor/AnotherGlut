#include "Engine.h"

Engine* Engine::engine = 0;

Engine::Engine(EngineConfiguration engineConfiguration)
{
	this->conf = engineConfiguration;
}

Engine* Engine::getInstance()
{
	if (engine == nullptr) {
		engine = new Engine(EngineConfiguration::getDefaultConfig());
	}
	return engine;
}

void Engine::clearScreen()
{

}

void Engine::start()
{
	glutMainLoop();
	return;
}

void Engine::loop(void)
{

}

void Engine::init(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(720, 600);
	glutCreateWindow("First time?");
	glutDisplayFunc(Engine::loop);
	return;
}
