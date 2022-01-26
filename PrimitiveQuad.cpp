#include "PrimitiveQuad.h"

PrimitiveQuad::PrimitiveQuad(Point3D p1, Point3D p2, Point3D p3, Point3D p4, ColorRGB col)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->col = col;
}

void PrimitiveQuad::translate(Point3D t)
{
	this->p1 = p1 + t;
	this->p2 = p2 + t;
	this->p3 = p3 + t;
	this->p4 = p4 + t;
}

void PrimitiveQuad::draw()
{
	using namespace glm;

	glEnableClientState(GL_VERTEX_ARRAY);
	float temp_w[] = {
		p1.getX(),p1.getY(),p1.getZ(),
		p2.getX(),p2.getY(),p2.getZ(),
		p3.getX(),p3.getY(),p3.getZ(),
		p4.getX(),p4.getY(),p4.getZ() };

	glVertexPointer(3, GL_FLOAT, 0, temp_w);

	glEnableClientState(GL_COLOR_ARRAY);
	float temp_col[] = {
		col.r,col.g,col.b ,
		col.r,col.g,col.b ,
		col.r,col.g,col.b ,
		col.r,col.g,col.b };
	glColorPointer(3, GL_FLOAT, 0, temp_col);

	glDrawArrays(GL_QUADS, 0, 12);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}


