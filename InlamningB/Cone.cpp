#include "Cone.h"



Cone::Cone(string shapeName, float C_radius, int C_height)
	:Shape(shapeName)
{
	this->C_radius = C_radius;
	this->C_height = C_height;
}

Cone::Cone(const Cone& origObj)
	:Shape(origObj)
{
	this->C_radius = origObj.C_radius;
	this->C_height = origObj.C_height;
}

Cone& Cone::operator=(const Cone& origObj)
{
	Cone::operator=(origObj);
	this->C_radius = origObj.C_radius;
	this->C_height = origObj.C_height;
	return *this;
}


Cone::~Cone()
{
}

float Cone::getC_radius() const
{
	return this->C_radius;
}

int Cone::getC_height() const
{
	return this->C_height;
}

string Cone::toStringAsCone() const
{
	return "| radius: " + to_string(this->C_radius) + " | height: " + to_string(this->C_height) + " |\n";
}
