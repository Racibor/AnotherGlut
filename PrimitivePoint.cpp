#include "PrimitivePoint.h"

PrimitivePoint::PrimitivePoint(Point3D w, ColorRGB col)
{
	this->w = w;
	this->col = col;
}
void PrimitivePoint::translate(Point3D t)
{
	this->w = this->w + t;
}

void PrimitivePoint::draw()
{
	using namespace glm;

	glEnableClientState(GL_VERTEX_ARRAY);
	float temp_w[] = { w.getX(),w.getY(),w.getZ() };
	glVertexPointer(3, GL_FLOAT, 0, temp_w);

	glEnableClientState(GL_COLOR_ARRAY);
	float temp_col[] = { col.r,col.g,col.b };
	glColorPointer(3, GL_FLOAT, 0, temp_col);

	glDrawArrays(GL_POINTS, 0, 3);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}


