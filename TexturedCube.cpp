#include "TexturedCube.h"

void TexturedCube::initTexturedCube(float size, int width, int height, unsigned char* texture)
{
	for (int i = 0; i < 72; i++)
		cube_vert[i] *= size;

	glGenTextures(1, TexID);
	glBindTexture(GL_TEXTURE_2D, TexID[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);
}

void TexturedCube::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, cube_vert);
	glTexCoordPointer(2, GL_FLOAT, 0, cube_texc);

	glBindTexture(GL_TEXTURE_2D, TexID[0]);
	glDrawElements(GL_TRIANGLES, sizeof(cube_ind), GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void TexturedCube::translate(Point3D t)
{
	for (int i = 0; i < 72; i++)
	{
		switch (i % 3)
		{
		case 0:
			cube_vert[i] += t.getX();
			break;
		case 1:
			cube_vert[i] += t.getY();
			break;
		case 2:
			cube_vert[i] += t.getZ();
			break;
		}
	}
}
