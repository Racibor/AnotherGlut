#pragma once
#include "ShapeObject.h"
#include "Point3D.h"
#include "ColorRGB.h"
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class PrimitiveQuad: public ShapeObject
{

private:
	Point3D p1;
	Point3D p2;
	Point3D p3;
	Point3D p4;
	ColorRGB col;
public:
	PrimitiveQuad(Point3D p1, Point3D p2, Point3D p3,Point3D p4, ColorRGB col);
	void translate(Point3D t);
	void draw();
};

