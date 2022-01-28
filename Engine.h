#pragma comment(lib, "freeglut.lib")
#pragma once
#include <iostream>
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "PrimitivePoint.h"
#include "PrimitiveLine.h"
#include "PrimitiveTriangle.h"
#include "PrimitiveQuad.h"
#include "Player.h"
#include "PrimitiveCube.h"
#include "BitmapHandler.h"
#include "TexturedCube.h"
#include "Anim8torSupport.h"
/*!
 * @brief Klasa definiujaca silnik i jego metody
*/
class Engine
{
private:
	/*!
	 * @brief Prywatny konstruktor (Singleton)
	 * @param engineConfiguration Konfiguracja silnika
	*/
	Engine(EngineConfiguration engineConfiguration);
public:
	//! Konfiguracja silnika
	EngineConfiguration conf;
	//! Wskaznik na silnik
	static Engine* engine;
	/*!
	 * @brief Tworzy nowy obiekt silnika, lub zwraca istniejacy
	 * @return Obiekt silnika
	*/
	static Engine* getInstance();
	/*!
	 * @brief Inicjalizuje parametry poczatkowe silnika i definiuje obiekty dla sceny
	*/
	void start();
	/*!
	 * @brief Metoda petli glownej silnika
	*/
	static void loop(void);
	/*!
	 * @brief Inicjalizuje i tworzy silnik
	*/
	void init(int argc, char* argv[]);
	/*!
	 * @brief Poprawia rozdzielczosc ekranu przy zmianie rozmiaru okna
	 * @param w Nowa szerokosc ekranu
	 * @param h Nowa wysokosc ekranu
	*/
	static void onScreenSizeChange(GLsizei w, GLsizei h);
	/*!
	 * @brief Wykonuje dane zadania, gdy silnik jest bezczynny
	*/
	static void OnIdle();
	/*!
	 * @brief Odpowiada za staly framerate silnika
	*/
	static void OnTimer(int val);
	/*!
	 * @brief Ustawia kamere przy uzyciu myszki 
	*/
	static void processMouse(int xx, int yy);
	/*!
	 * @brief Porusza kamere przy uzyciu klawiatury
	*/
	static void processKeys(unsigned char key, int xx, int yy);
};

