#pragma once
#include "Anim8orExport.h"
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Anim8torSupport
{
public:
	static void draw(struct Anim8orObject* obj);
	static void drawTex(Anim8orObject* obj, int tex_id);
};

