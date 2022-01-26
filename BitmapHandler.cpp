#include "BitmapHandler.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void BitmapHandler::LoadTexture(const char* name, int w, int h, int nchan)
{
	width = w;
	height = h;
	tex = stbi_load(name, &w, &h, &nchan, 0);
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
