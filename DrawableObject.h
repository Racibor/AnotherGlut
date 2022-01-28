#pragma once
/*!
 * @brief Klasa abstrakcyjna obiektu rysowalnego
*/
class DrawableObject
{
public:
	/*!
	 * @brief Rysuje obiekt
	*/
	void virtual draw() = 0;
};

