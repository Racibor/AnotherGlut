#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShapeObject.h"

/*!
 * @brief Klasa definiujaca prymitywny szescian zawierajacy teksture
*/
class TexturedCube: public ShapeObject
{
private:

	GLuint TexID[1];

	float cube_vert[72] = {
		-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,	-1.0f,  1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,	 1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	 1.0f, -1.0f,  1.0f,
		 1.0f, -1.0f, -1.0f,	 1.0f,  1.0f, -1.0f,	 1.0f, -1.0f,  1.0f,	 1.0f,  1.0f,  1.0f,
		-1.0f, -1.0f, -1.0f,	-1.0f, -1.0f,  1.0f,	-1.0f,  1.0f, -1.0f,	-1.0f,  1.0f,  1.0f,
	};

	const float cube_texc[48] = {
		0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f,
		1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
		1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
		0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f,
		1.0f, 0.0f,		1.0f, 1.0f,		0.0f, 0.0f,		0.0f, 1.0f,
		0.0f, 0.0f,		1.0f, 0.0f,		0.0f, 1.0f,		1.0f, 1.0f
	};
	const unsigned char cube_ind[36] = {
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

public:
	/*!
     * @brief Konstruktor prymitywnego szescianu z tekstura
     * @param size Rozmiar
     * @param col Kolor
     * @param texture Tekstura
	*/
	void initTexturedCube(float size, int width, int height, unsigned char* texture);
	/*!
	 * @brief Rysuje teksturowany szescian
	*/
	void draw();
	/*!
	* @brief Przemieszcza szescian o dany wektor wyznaczany przez punkt
	* @param t Wektor wyrazany przez punkt do przemieszczenia
	*/
	void translate(Point3D t);
};

