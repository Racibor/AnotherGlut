#include "Point3D.h"

void Point3D::setX(float x)
{
	this->x = x;
}
void Point3D::setY(float y)
{
	this->y = y;
}
void Point3D::setZ(float z)
{
	this->z = z;
}
float Point3D::getX()
{
	return x;
}
float Point3D::getY()
{
	return y;
}
float Point3D::getZ()
{
	return z;
}

Point3D::Point3D()
{
	return;
}

Point3D::Point3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Point3D Point3D::operator+(Point3D a)
{
	return Point3D(this->getX() + a.getX(), this->getY() + a.getY(), this->getZ() + a.getZ());
}