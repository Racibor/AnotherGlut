#pragma once
#include "ShapeObject.h"
#include "Point3D.h"
#include "ColorRGB.h"
#include <iostream>
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class PrimitivePoint: public ShapeObject
{
private:
	Point3D w;
	ColorRGB col;
public:
	PrimitivePoint(Point3D w, ColorRGB col);
	void translate(Point3D t);
	void draw();

};

