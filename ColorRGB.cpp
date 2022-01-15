#include "ColorRGB.h"

ColorRGB::ColorRGB()
{
	return;
}

ColorRGB::ColorRGB(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}
float ColorRGB::getR()
{
	return r;
}
float ColorRGB::getG()
{
	return g;
}
float ColorRGB::getB()
{
	return b;
}