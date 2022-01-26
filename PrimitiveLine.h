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

class PrimitiveLine: public ShapeObject
{
private:
	Point3D p1;
	Point3D p2;
	ColorRGB col;
public:
	PrimitiveLine(Point3D p1,Point3D p2, ColorRGB col);
	void translate(Point3D t);
	void draw();
};

