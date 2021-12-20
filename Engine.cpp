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
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	// Z-buffer ON:
	glEnable(GL_DEPTH_TEST);
	// Lighting ON:
	glEnable(GL_LIGHTING);

	// Global lighting parameters:
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);

	// Light parameters for light #0:
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);
	// Enable light #0:
	glEnable(GL_LIGHT0);

	// Material parameters (common for all objects):
	glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpc);
	glMateriali(GL_FRONT, GL_SHININESS, 64);
	// Color material ON:
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glutMainLoop();
	return;
}
static int i = 0;
void Engine::loop(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Switch to model-view matrix:
	glMatrixMode(GL_MODELVIEW);

	// Move scene center away from the camera:
	glm::mat4 MatM = glm::translate(glm::vec3(0, 0, -300));
	
	// Fixed light position - it's not moving with objects:
	glLoadMatrixf(glm::value_ptr(MatM));
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// Animation:
	MatM = glm::rotate(MatM, glm::radians(angle*5), glm::vec3(0, 1, 1));
	// 120 deg rotation:
	glm::mat4 MatRot120 = glm::rotate(glm::radians(120.0f), glm::vec3(0, 1, 0));
	// Three objects rotating around the middle point:
	glm::mat4 m1 = MatM * MatRot120;
	glLoadMatrixf(glm::value_ptr(m1));
	glColor3f(1, 0, 0);
	glutSolidCube(50);	// Green cube

	glutSwapBuffers();
}

void Engine::init(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("First time?");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(Engine::loop);
	glutReshapeFunc(Engine::onScreenSizeChange);
	glutIdleFunc(Engine::OnIdle);

	return;
}

void Engine::onScreenSizeChange(GLsizei w, GLsizei h)
{
	if (h == 0)	h = 1;
	glViewport(0, 0, w, h);
	// Switch to projection matrix:
	glMatrixMode(GL_PROJECTION);
	// Perspective projection:
	glm::mat4 MatP = glm::perspective<float>(glm::radians(50.0f), (float)w / h, 130, 470);
	glLoadMatrixf(glm::value_ptr(MatP));
}


void Engine::OnIdle() {
	static int last_time;
	// Time in milliseconds:
	int now_time = glutGet(GLUT_ELAPSED_TIME);

	if (last_time > 0) {
		float times = (now_time - last_time) / 1000.0f;
		// Angle change during animation (25 deg per second):
		angle += times * 25;
		if (angle >= 360)	angle -= 360;
	}
	// Copy for measuring the next frame:
	last_time = now_time;
	// Refresh frame:
	glutPostRedisplay();
}