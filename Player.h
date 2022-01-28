#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Point3D.h"
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/matrix_transform.hpp>

/*!
 * @brief Klasa definiujaca gracza i jego kamere
*/
class Player
{
public:
	//! Wektor pozycji
	glm::vec3 position;
	//! Wektor punktu, w ktory patrzy gracz
	glm::vec3 lookingAt;
	//! Wektor normalny gracza
	glm::vec3 upVec;
	//! Horyzontalne polozenie myszki
	float yaw;
	//! Wertykalne polozenie myszki
	float pitch;
	//! Czulosc kamery i sterowania
	float sensitivity = 1.0f;

	/*!
	 * @brief Przemieszcza gracza wzgledem danego wektora
	 * @param v Wektor definiujacy przemieszczenie
	*/
	void move(glm::vec3 v);
	/*!
	 * @brief Ustawia pozycje poczatkowa i parametry kamery
	*/
	void defaultPos();
	/*!
	 * @brief Zwraca macierz widoku kamery gracza
	 * @return Macierz widoku
	*/
	glm::mat4 getCameraViewMatrix();
};

