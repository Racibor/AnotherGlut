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
 * @brief Klasa opisujaca prymitywny czworokat
*/
class PrimitiveQuad: public ShapeObject
{
private:
	//! Punkt pierwszy
	Point3D p1;
	//! Punkt drugi
	Point3D p2;
	//! Punkt trzeci
	Point3D p3;
	//! Punkt czwarty
	Point3D p4;
	//! Kolor
	ColorRGB col;
public:
	/*!
	 * @brief Konstruktor definiujacy prymitywny czworokat
	 * @param p1 Punkt pierwszy
	 * @param p2 Punkt drugi
	 * @param p3 Punkt trzeci
	 * @param p4 Punkt czwarty
	 * @param col Kolor
	*/
	PrimitiveQuad(Point3D p1, Point3D p2, Point3D p3,Point3D p4, ColorRGB col);
	/*!
	* @brief Przemieszcza czworokat o dany wektor wyznaczany przez punkt
	* @param t Wektor wyrazany przez punkt do przemieszczenia
	*/
	void translate(Point3D t);
	/*!
	 * @brief Rysuje czworokat
	*/
	void draw();
};

