#pragma once
#include "Point3D.h"
/*!
 * @brief Klasa opisujaca obiekt zdolny do transformacji
*/
class TransformableObject
{
public:
    /*!
    * @brief Przemieszcza obiekt o dany wektor wyznaczany przez punkt
    * @param t Wektor wyrazany przez punkt do przemieszczenia
    */
    void virtual translate(Point3D t) = 0;
};

