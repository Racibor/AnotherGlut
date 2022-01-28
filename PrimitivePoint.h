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

/*!
 * @brief Klasa opisujaca prymitywny punkt
*/
class PrimitivePoint: public ShapeObject
{
private:
	//! Wspolrzedne punktu
	Point3D w;
	//! Kolor
	ColorRGB col;
public:
	/*!
	 * @brief Konstruktor definiujacy punkt
	 * @param w Wspolrzedne punktu
	 * @param col Kolor
	*/
	PrimitivePoint(Point3D w, ColorRGB col);
	/*!
	* @brief Przemieszcza punkt o dany wektor wyznaczany przez punkt
	* @param t Wektor wyrazany przez punkt do przemieszczenia
	*/
	void translate(Point3D t);
	/*!
	 * @brief Rysuje punkt
	*/
	void draw();

};

