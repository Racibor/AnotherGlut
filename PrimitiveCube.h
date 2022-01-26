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

class PrimitiveCube: public ShapeObject
{
	float cube_vert[72] = {
	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f,  1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f, -1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,
	};

	unsigned char cube_ind[36] = {
		0, 1, 2,
		2, 1, 3,
		4, 5, 6,
		6, 5, 7,
		8, 9, 10,
		10, 9, 11,
		12, 13, 14,
		14, 13, 15,
		16, 17, 18,
		18, 17, 19,
		20, 21, 22,
		22, 21, 23,
	};
	float cube_norm[72] = {
		 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,	 0.0f, 0.0f, 1.0f,
		 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,	 0.0f, 0.0f,-1.0f,
		 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,	 0.0f, 1.0f, 0.0f,
		 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,	 0.0f,-1.0f, 0.0f,
		 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,	 1.0f, 0.0f, 0.0f,
		-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f,	-1.0f, 0.0f, 0.0f
	};
	float cube_cols[72] = {
		1.0f, 0.3f, 0.3f,	1.0f, 0.3f, 0.3f,	1.0f, 0.3f, 0.3f,	1.0f, 0.3f, 0.3f,
		1.0f, 1.0f, 0.3f,	1.0f, 1.0f, 0.3f,	1.0f, 1.0f, 0.3f,	1.0f, 1.0f, 0.3f,
		0.3f, 0.3f, 1.0f,	0.3f, 0.3f, 1.0f,	0.3f, 0.3f, 1.0f,	0.3f, 0.3f, 1.0f,
		0.3f, 1.0f, 1.0f,	0.3f, 1.0f, 1.0f,	0.3f, 1.0f, 1.0f,	0.3f, 1.0f, 1.0f,
		0.3f, 0.3f, 0.3f,	0.3f, 0.3f, 0.3f,	0.3f, 0.3f, 0.3f,	0.3f, 0.3f, 0.3f,
		0.3f, 1.0f, 0.3f,	0.3f, 1.0f, 0.3f,	0.3f, 1.0f, 0.3f,	0.3f, 1.0f, 0.3f
	};
public:
	PrimitiveCube(float size, ColorRGB col);
	void draw();
	void translate(Point3D t);	

};

