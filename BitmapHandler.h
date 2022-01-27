#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class BitmapHandler
{
private:
	GLuint TexID[1];
	unsigned char* tex;
	int width;
	int height;
public:
	void LoadTexture(const char* name, int w, int h, int nchan);
	void initializeTexture();
	void deleteTexture();
	unsigned char* getTexture();
	int getWidth();
	int getHeight();
	GLuint getTexID();
};

