#pragma once
/*!
 * @brief Klasa definiujaca punkt w przestrzeni trojwymiarowej
*/
class Point3D
{
private:
	//!Wspolrzedna x
	float x; 
	//!Wspolrzedna y
	float y;
	//!Wspolrzedna z
	float z;
public:
	/*!
	 * @brief Ustawia wspolrzedna x
	 * @param x Nowa wartosc x
	*/
	void setX(float x);
	/*!
	* @brief Ustawia wspolrzedna y
	* @param x Nowa wartosc y
	*/
	void setY(float y);
	/*!
	* @brief Ustawia wspolrzedna z
	* @param x Nowa wartosc z
	*/
	void setZ(float z);
	/*!
	 * @brief Zwraca wartosc wsporzednej x
	 * @return Wartosc wspolrzednej x
	*/
	float getX();
	/*!
	* @brief Zwraca wartosc wsporzednej y
	* @return Wartosc wspolrzednej y
	*/
	float getY();
	/*!
	 * @brief Zwraca wartosc wsporzednej z
	* @return Wartosc wspolrzednej z
	*/
	float getZ();
	/*!
	 * @brief Konstruktor domyslny
	*/
	Point3D();
	/*!
	 * @brief Konstruktor ustawiajacy parametry punkty
	 * @param x Wartosc wspolrzednej x
	 * @param y Wartosc wspolrzednej y
	 * @param z Wartosc wspolrzednej z
	*/
	Point3D(float x, float y, float z);
	/*!
	 * @brief Dodaje wspolrzedne dwoch punktow i zwraca nowy punkt
	 * @param a Punkt do dodania
	 * @return Nowy punkt wypadkowy
	*/
	Point3D operator+(Point3D a);
};

