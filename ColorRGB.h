#pragma once
/*!
 * @brief Klasa do przechowania koloru w formacie RGB
*/
class ColorRGB
{
public:
	//! Skladowa koloru R
	float r;
	//! Skladowa koloru B
	float g;
	//! Skladowa koloru B
	float b;
	/*!
	 * @brief Konstruktor domyslny
	*/
	ColorRGB();
	/*!
	 * @brief Konstruktor definiuj¹cy kolor
	 * @param r Skladowa koloru R
	 * @param g Skladowa koloru G
	 * @param b Skladowa koloru B
	*/
	ColorRGB(float r, float g, float b);
	/*!
	 * @brief Zwraca skladowa koloru R
	 * @return Wartosc skladowej koloru R
	*/
	float getR();
	/*!
	* @brief Zwraca skladowa koloru G
	* @return Wartosc skladowej koloru G
	*/
	float getG();
	/*!
	* @brief Zwraca skladowa koloru B
	* @return Wartosc skladowej koloru B
	*/
	float getB();
};

