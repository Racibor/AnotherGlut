#pragma once

class BitmapHandler
{
private:
	unsigned char* tex;
	int width;
	int height;
public:
	void LoadTexture(const char* name, int w, int h, int nchan);
	void deleteTexture();
	unsigned char* getTexture();
	int getWidth();
	int getHeight();
};

