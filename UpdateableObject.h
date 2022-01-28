#pragma once
/*!
 * @brief Klasa opisujaca obiekt ulegajacy aktualizacji stanu
*/
class UpdateableObject
{
public:
	 /*!
	  * @brief Aktualizuje stan obiektu
	 */
	 void virtual update() = 0;
};

