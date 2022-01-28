#pragma once
#include "Anim8orExport.h"
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*!
 * @brief Klasa do obslugi modeli wykonanych w anim8tor w formacie *.c
*/
class Anim8torSupport
{
public:
	/*!
	 * @brief Rysuje model z programu anim8tor
	 * @param obj Obiekt modelu do rysowania
	*/
	static void draw(struct Anim8orObject* obj);
	/*!
	 * @brief Rysuje model z programu anim8tor
	 * @param obj Obiekt modelu do rysowania
	 * @param tex_id ID tekstury dla modelu
	*/
	static void drawTex(Anim8orObject* obj, int tex_id);
};

