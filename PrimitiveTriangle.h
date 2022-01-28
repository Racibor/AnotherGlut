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

/*!
 * @brief Klasa opisujaca prymitywny trojkat
*/
class PrimitiveTriangle: public ShapeObject
{
private:
	//! Punkt pierwszy
	Point3D p1;
	//! Punkt drugi
	Point3D p2;
	//! Punkt trzeci
	Point3D p3;
	//! Kolor
	ColorRGB col;
public:
	/*!
	 * @brief Konstruktor definiujacy prymitywny trojkat
	 * @param p1 Punkt pierwszy
	 * @param p2 Punkt drugi
	 * @param p3 Punkt trzeci
	 * @param col Kolor
	*/
	PrimitiveTriangle(Point3D p1, Point3D p2,Point3D p3, ColorRGB col);
	/*!
	* @brief Przemieszcza trojkat o dany wektor wyznaczany przez punkt
	* @param t Wektor wyrazany przez punkt do przemieszczenia
	*/
	void translate(Point3D t);
	/*!
	 * @brief Rysuje trojkat
	*/
	void draw();
};

