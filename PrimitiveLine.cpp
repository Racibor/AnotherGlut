#include "PrimitiveLine.h"

PrimitiveLine::PrimitiveLine(Point3D p1, Point3D p2, ColorRGB col)
{
	this->p1 = p1;
	this->p2 = p2;
	this->col = col;
}

void PrimitiveLine::translate(Point3D t)
{
	this->p1 = this->p1 + t;
	this->p2 = this->p2 + t;
}

void PrimitiveLine::draw()
{
	using namespace glm;

	glEnableClientState(GL_VERTEX_ARRAY);
	float temp_w[] = { p1.getX(),p1.getY(),p1.getZ(), p2.getX(),p2.getY(),p2.getZ() };
	glVertexPointer(3, GL_FLOAT, 0, temp_w);

	glEnableClientState(GL_COLOR_ARRAY);
	float temp_col[] = { 
		col.r,col.g,col.b,
		col.r,col.g,col.b};
	glColorPointer(3, GL_FLOAT, 0, temp_col);

	glDrawArrays(GL_LINES, 0, 6);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void PrimitiveLine::scale()
{
}

void PrimitiveLine::rotate()
{
}
