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
	glClearColor(0.1, 0.1, 0.2, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0, 0.5f);
	glutSolidCube(100.0f);
	glutSwapBuffers();
}

void Engine::init(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("First time?");
	glutDisplayFunc(Engine::loop);
	glutReshapeFunc(Engine::onScreenSizeChange);
	return;
}

void Engine::onScreenSizeChange(GLsizei w, GLsizei h)
{
	// No division by zero:
	if (h == 0)	h = 1;
	if (w == 0)	w = 1;
	// Set viewport:
	glViewport(0, 0, w, h);
	// Projection matrix:
	glm::mat4 MatP;
	// Clip space with respect to the window size ratio (float constants!):
	if (w < h)	MatP = glm::ortho(-100.0f, 100.0f, -100.0f * h / w, 100.0f * h / w, 100.0f, -100.0f);
	else		MatP = glm::ortho(-100.0f * w / h, 100.0f * w / h, -100.0f, 100.0f, 100.0f, -100.0f);
	glLoadMatrixf(glm::value_ptr(MatP));
}
