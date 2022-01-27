#include "BitmapHandler.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void BitmapHandler::LoadTexture(const char* name, int w, int h, int nchan)
{
	width = w;
	height = h;
	tex = stbi_load(name, &w, &h, &nchan, 0);
}

void BitmapHandler::initializeTexture()
{
	glGenTextures(1, TexID);
	glBindTexture(GL_TEXTURE_2D, TexID[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
}

void BitmapHandler::deleteTexture()
{
	stbi_image_free(tex);
}

unsigned char* BitmapHandler::getTexture()
{
	return tex;
}

int BitmapHandler::getWidth()
{
	return width;
}

int BitmapHandler::getHeight()
{
	return height;
}

GLuint BitmapHandler::getTexID()
{
	return TexID[0];
}
