#include "PrimitiveCube.h"

void PrimitiveCube::draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, cube_vert);

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, cube_norm);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 0, cube_cols);

	glDrawElements(GL_TRIANGLES, sizeof(cube_ind), GL_UNSIGNED_BYTE, cube_ind);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
void PrimitiveCube::translate(Point3D t)
{
	for (int i = 0; i < 72; i++)
	{
		switch (i%3)
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

PrimitiveCube::PrimitiveCube(float size, ColorRGB col)
{
	for (int i = 0; i < 72; i++)
		cube_vert[i] *= size;
}
