#include "Cone.h"

Cone::Cone(string shapeName, int height, float C_radius)
	:Shape(shapeName, height)
{
	this->C_radius = C_radius;
}

Cone::Cone(const Cone& origObj)
	:Shape(origObj)
{
	this->C_radius = origObj.C_radius;
}

Cone& Cone::operator=(const Cone& origObj)
{
	operator=(origObj);
	this->C_radius = origObj.C_radius;
	return *this;
}


Cone::~Cone()
{
}

float Cone::getC_radius() const
{
	return this->C_radius;
}

float Cone::getC_volume() const
{
	return ((3.1415*(this->getC_radius()*this->getC_radius())*this->getHeight()) / 3);
}

void Cone::setC_radius(float C_radius)
{
	this->C_radius = C_radius;
}

string Cone::toStringSpecific() const
{
	return "| radius: " + to_string(this->C_radius) + " | volume: " + to_string(this->getC_volume()) + " |\n";
}
