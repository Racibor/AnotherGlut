#include "Engine.h"
#include "models/vase.c"
#include "models/earth2.c"
#include "models/astro2.c"

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

struct playerData {
	float angle;
	float lx, lz;
	float x, z;
}pd = {0.0,0.0,-1.0,0.0,5.0};

static BitmapHandler BHandler;
static BitmapHandler Tex_Skybox;
static BitmapHandler Tex_Earth;
static TexturedCube TCube;
static TexturedCube Skybox;
static PrimitiveQuad myQuad(Point3D(-50.0f, -50.0f, -50.0f), Point3D(50.0f, -50.0f, -50.0f), Point3D(50.0f, -50.0f, 50.0f), Point3D(-50.0f, -50.0f, 50.0f), ColorRGB(0.0f, 0.0f, 1.0f));
static PrimitiveCube myCube(10.0f, ColorRGB(1.0f, 0.0f, 0.0f));
static Player myPlayer;

void Engine::start()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);    

	GLfloat LightAmb[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat LightDif[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat LightPos[] = { 0, 100, 100, 1.0 };
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
	glutSetCursor(GLUT_CURSOR_NONE);
	myPlayer.defaultPos();

	BHandler.LoadTexture("gfx/test.bmp", 128, 128, 3);
	Tex_Earth.LoadTexture("gfx/earth.bmp", 1024, 1024, 3);
	Tex_Skybox.LoadTexture("gfx/sky.bmp", 720, 720, 3);
	//Tex_Skybox.LoadTexture("sky.bmp", 720, 720, 3);
	if (!BHandler.getTexture())printf("Texture load failed!\n");
	if (!Tex_Earth.getTexture())printf("Texture load failed!\n");
	if (!Tex_Skybox.getTexture())printf("Texture load failed!\n");
	Tex_Earth.initializeTexture();

	TCube.initTexturedCube(15.0f, BHandler.getWidth(), BHandler.getHeight(), BHandler.getTexture());
	Skybox.initTexturedCube(500.0f, Tex_Skybox.getWidth(), Tex_Skybox.getHeight(), Tex_Skybox.getTexture());

	TCube.translate(Point3D(0.0f, 30.0f, 0.0f));
	myCube.translate(Point3D(0.0f, -20.0f, 0.0f));


	glutMainLoop();
	return;
}

GLfloat angle = 0; // DO AN
GLfloat plrObjectOffsetX = 0;
GLfloat plrObjectOffsetZ = 0;

void Engine::loop(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  //TO MUSI BYÆ

	glMatrixMode(GL_MODELVIEW);

	glm::mat4 MatM = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f));
	MatM = MatM * myPlayer.Look();
	glLoadMatrixf(glm::value_ptr(MatM));

	MatM = glm::translate(MatM,glm::vec3(0.0f, 0.0f, -250.0f));
	MatM = glm::rotate(MatM, angle*0.5f, glm::vec3(0, 1, 0));
	glLoadMatrixf(glm::value_ptr(MatM));
	Anim8torSupport::drawTex(&object_earth, Tex_Earth.getTexID());

	MatM = glm::rotate(MatM, angle, glm::vec3(0, 1, 0));
	MatM = glm::translate(MatM, glm::vec3(120, -20, 0));
	
	glLoadMatrixf(value_ptr(MatM));
	TCube.draw();

	MatM = glm::rotate(MatM, 2*angle, glm::vec3(0, 1, 0));
	MatM = glm::translate(MatM, glm::vec3(40, 10, 0));

	glLoadMatrixf(value_ptr(MatM));
	Anim8torSupport::draw(&object_vase);

	glm::mat4 MatM2 = glm::translate(glm::vec3(-10.0f + plrObjectOffsetX * 3 ,-15.0f,-45.0f + plrObjectOffsetZ * 3));
	glLoadMatrixf(glm::value_ptr(MatM2));
	Anim8torSupport::draw(&object_astro);

	glm::mat4 MatM3 = glm::translate(glm::vec3(0.0f, 0.0f, 0.0f)) * myPlayer.Look();
	MatM3 = glm::translate(MatM3, glm::vec3(myPlayer.position));
	glLoadMatrixf(glm::value_ptr(MatM3));
	Skybox.draw();

	plrObjectOffsetZ = (plrObjectOffsetZ <= 0.0) ? (plrObjectOffsetZ):(plrObjectOffsetZ - 0.02);
	plrObjectOffsetZ = (plrObjectOffsetZ >= 0.0) ? (plrObjectOffsetZ):(plrObjectOffsetZ + 0.02);
	plrObjectOffsetX = (plrObjectOffsetX <= 0.0) ? (plrObjectOffsetX):(plrObjectOffsetX - 0.02);
	plrObjectOffsetX = (plrObjectOffsetX >= 0.0) ? (plrObjectOffsetX):(plrObjectOffsetX + 0.02);
	
	glutSwapBuffers();
}


#define ANIM_FPS 60

void OnTimer(int val) {
	angle = (angle == 360) ? 0 : (angle + 0.01);
	glutPostRedisplay();
	glutTimerFunc(1000 / ANIM_FPS, OnTimer, 0);
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
	glutPassiveMotionFunc(Engine::processMouse);
	glutKeyboardFunc(Engine::processKeys);
	glutTimerFunc(1000 / ANIM_FPS, OnTimer, 0);

	return;
}

void Engine::onScreenSizeChange(GLsizei w, GLsizei h)
{
	if (h == 0)	h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glm::mat4 MatP = glm::perspective<float>(glm::radians(50.0f), (float)w / h, 10, 800);
	glLoadMatrixf(glm::value_ptr(MatP));
}


void Engine::OnIdle() {

	glutPostRedisplay();
}

void Engine::processKeys(unsigned char key, int xx, int yy)
{
	switch (key)
	{
	case 'w':
		myPlayer.position += myPlayer.sensitivity * myPlayer.lookingAt;
		plrObjectOffsetZ = (plrObjectOffsetZ < 1.0) ? (plrObjectOffsetZ + 0.1) : (plrObjectOffsetZ);
		break;
	case 's':
		myPlayer.position -= myPlayer.sensitivity * myPlayer.lookingAt;
		plrObjectOffsetZ = (plrObjectOffsetZ > -1.0) ? (plrObjectOffsetZ - 0.1) : (plrObjectOffsetZ);
		break;
	case 'a':
		myPlayer.position -= glm::normalize(glm::cross(myPlayer.lookingAt, myPlayer.upVec)) * myPlayer.sensitivity;
		plrObjectOffsetX = (plrObjectOffsetX < 1.0) ? (plrObjectOffsetX + 0.1) : (plrObjectOffsetX);
		break;
	case 'd':
		myPlayer.position += glm::normalize(glm::cross(myPlayer.lookingAt, myPlayer.upVec)) * myPlayer.sensitivity;
		plrObjectOffsetX = (plrObjectOffsetX > -1.0) ? (plrObjectOffsetX - 0.1) : (plrObjectOffsetX);
		break;
	case 'm':
		glutLeaveMainLoop();
		break;
	}
}

void Engine::processMouse(int xx, int yy)
{
	float xoffset = xx - 1280 / 2;
	float yoffset = 720 / 2 - yy;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	myPlayer.yaw += xoffset;
	myPlayer.pitch += yoffset;

	if (myPlayer.pitch > 89.0f)
		myPlayer.pitch = 89.0f;
	if (myPlayer.pitch < -89.0f)
		myPlayer.pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(myPlayer.yaw)) * cos(glm::radians(myPlayer.pitch));
	direction.y = sin(glm::radians(myPlayer.pitch));
	direction.z = sin(glm::radians(myPlayer.yaw)) * cos(glm::radians(myPlayer.pitch));
	myPlayer.lookingAt = glm::normalize(direction);

	glutWarpPointer(1280 / 2, 720 / 2);
}



