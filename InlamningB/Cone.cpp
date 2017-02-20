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

void Cone::setC_radius(float C_radius)
{
	this->C_radius = C_radius;
}

string Cone::toStringSpecific() const
{
	return "| radius: " + to_string(this->C_radius) + " |\n";
}
