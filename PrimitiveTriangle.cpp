#include "PrimitiveTriangle.h"

PrimitiveTriangle::PrimitiveTriangle(Point3D p1, Point3D p2, Point3D p3, ColorRGB col)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->col = col;
}

void PrimitiveTriangle::translate(Point3D t)
{
	this->p1 = p1 + t;
	this->p2 = p2 + t;
	this->p3 = p3 + t;
}

void PrimitiveTriangle::draw()
{
	using namespace glm;

	glEnableClientState(GL_VERTEX_ARRAY);
	float temp_w[] = { 
		p1.getX(),p1.getY(),p1.getZ(), 
		p2.getX(),p2.getY(),p2.getZ(),
		p3.getX(),p3.getY(),p3.getZ()};

	glVertexPointer(3, GL_FLOAT, 0, temp_w);

	glEnableClientState(GL_COLOR_ARRAY);
	float temp_col[] = {
		col.r,col.g,col.b ,
		col.r,col.g,col.b ,
		col.r,col.g,col.b };
	glColorPointer(3, GL_FLOAT, 0, temp_col);

	glDrawArrays(GL_TRIANGLES, 0, 9);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void PrimitiveTriangle::scale()
{
}

void PrimitiveTriangle::rotate()
{
}
