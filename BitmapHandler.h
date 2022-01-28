#pragma once
#include <windows.h>
#include "EngineConfiguration.h"
#include <gl\gl.h>
#include <gl\freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*!
 * @brief Klasa do wczytywania lub przechowywania tekstur 
*/
class BitmapHandler
{
private:
	//! ID Tekstury
	GLuint TexID[1];
	//! Tekstura
	unsigned char* tex;
	//! Szerokosc
	int width;
	//! Wysokosc
	int height;
public:
	/*!
	 * @brief Wczytuje plik z tekstura i zapisuje je do pol obiektu
	 * @param name Sciezka do pliku
	 * @param w Szerokosc
	 * @param h Wysokosc
	 * @param nchan Ilosc kanalow koloru
	*/
	void LoadTexture(const char* name, int w, int h, int nchan);
	/*!
	 * @brief Wczytuje plik z tekstura i zwraca otrzymany obiekt tekstury
	 * @param name Sciezka do pliku
	 * @param w Szerokosc
	 * @param h Wysokosc
	 * @param nchan Ilosc kanalow koloru
	 * @return Obiekt typu unsigned char * zawierajacy teksture
	*/
	static unsigned char* LoadRawTexture(const char* name, int w, int h, int nchan);
	/*!
	 * @brief Inicjalizuje teksture, pozwalajac na wykorzystanie calego obiektu jako teksture do OpenGL
	*/
	void initializeTexture();
	/*!
	 * @brief Usuwa teksture
	*/
	void deleteTexture();
	/*!
	 * @brief Zwraca obiekt zawierajacy teksture
	 * @return Obiekt zawierajacy teksture
	*/
	unsigned char* getTexture();
	/*!
	 * @brief Zwraca szerokosc tekstury
	 * @return Szerokosc tekstury
	*/
	int getWidth();
	/*!
	 * @brief Zwraca wysokosc tekstury
	 * @return Wysokosc tekstury
	*/
	int getHeight();
	/*!
	 * @brief Zwraca ID tekstury do wykorzystania z OpenGL
	 * @return ID tekstury
	*/
	GLuint getTexID();
};

