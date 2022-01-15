#pragma once
class Point3D
{
private:
	float x, y, z;
public:
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	float getX();
	float getY();
	float getZ();
	Point3D();
	Point3D(float x, float y, float z);
	Point3D operator+(Point3D a);
};

