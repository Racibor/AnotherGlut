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

struct playerData {
	float angle;
	float lx, lz;
	float x, z;
}pd = {0.0,0.0,-1.0,0.0,5.0};


//GLfloat LightAmb[] = { 0.1, 0.1, 0.1, 1.0 };
//GLfloat LightDif[] = { 0.7, 0.7, 0.7, 1.0 };
//GLfloat LightPos[] = { 0, 2, 15, 1.0 };
//GLfloat LightSpec[] = { 1, 1, 1, 1 };

void Engine::start()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_LIGHTING);

	GLfloat LightAmb[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat LightDif[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat LightPos[] = { 0, 102, 15, 1.0 };
	GLfloat LightSpec[] = { 1, 1, 1, 1 };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPos);

	glEnable(GL_LIGHT0);

	glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpec);
	glMateriali(GL_FRONT, GL_SHININESS, 64);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
	return;
}

void Engine::loop(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  //TO MUSI BYÆ
	glMatrixMode(GL_MODELVIEW);


	glm::mat4 MatM = glm::translate(glm::vec3(0.0f, 0.0f, -200.0f));
	glLoadMatrixf(glm::value_ptr(MatM));   //TU SIE USTAWIA I WRZUCA CENTRUM RYSOWANKA
	gluLookAt(pd.x, 1.0f, pd.z, pd.x + pd.lx, 1.0f, pd.z + pd.lz, 0.0f, 1.0f, 0.0f);


	//TUTAJ WRZUCAC CO CHCECIE

	PrimitivePoint P(Point3D(-5.0f, -5.0f, -5.0f), ColorRGB(1.0f, 1.0f, 1.0f));
	PrimitiveLine myLine(Point3D(-25.0f, -10.0f, 30.0f), Point3D(25.0f, 10.0f, 30.0f), ColorRGB(1.0f, 0.0f, 0.0f));
	PrimitiveTriangle myTriangle(Point3D(0.0f, 0.0f, 0.0f), Point3D(10.0f, 20.0f, 0.0f), Point3D(20.0f, 0.0f, 0.0f), ColorRGB(0.0f, 1.0f, 0.0f));
	PrimitiveQuad myQuad(Point3D(-30.0f, 0.0f, 20.0f), Point3D(-30.0f, 10.0f, 20.0f), Point3D(-20.0f, 10.0f, 20.0f), Point3D(-20.0f, 0.0f, 20.0f), ColorRGB(0.0f, 0.0f, 1.0f));
	PrimitiveCube myCube(10.0f, ColorRGB(1.0f, 0.0f, 0.0f));
	myCube.translate(Point3D(0.0f, -20.0f, 0.0f));

	P.draw();
	//myLine.draw();
	myTriangle.draw(); 
	myCube.draw();
	myQuad.draw();


	

	//TUTAJ JUZ NIE

	glutSwapBuffers();
}




void Engine::init(int argc, char* argv[])
{
	glutInit(&argc, argv);
	

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Piekny engine by knadi, kewkacpi, wiksondixon");

	glutDisplayFunc(Engine::loop);
	glutReshapeFunc(Engine::onScreenSizeChange);
	glutIdleFunc(Engine::OnIdle);
	glutSpecialFunc(Engine::processSpecialKeys);

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
	glutPostRedisplay();
}


void Engine::processSpecialKeys(int key, int xx, int yy)
{
	float fraction = 0.5f;

	switch (key) {
	case GLUT_KEY_LEFT:
		pd.angle -= 0.03f;
		pd.lx = sin(pd.angle);
		pd.lz = -cos(pd.angle);
		break;
	case GLUT_KEY_RIGHT:
		pd.angle += 0.03f;
		pd.lx = sin(pd.angle);
		pd.lz = -cos(pd.angle);
		break;
	case GLUT_KEY_UP:
		pd.x += pd.lx * fraction;
		pd.z += pd.lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		pd.x -=pd.lx * fraction;
		pd.z -=pd.lz * fraction;
		break;
	}
}