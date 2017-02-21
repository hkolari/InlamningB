#include "Shape.h"


Shape::Shape(string shapeName, int height)
{
	this->shapeName = shapeName;
	this->height = height;
}

Shape::Shape(const Shape& origObj)
{
	this->shapeName = origObj.shapeName;
	this->height = origObj.height;
}

Shape& Shape::operator=(const Shape& origObj)
{
	this->shapeName = origObj.shapeName;
	this->height = origObj.height;
	return *this;
}

Shape::~Shape()
{
}

string Shape::getShapeName() const
{
	return this->shapeName;
}

int Shape::getHeight() const
{
	return this->height;
}

void Shape::setHeight(int height)
{
	this->height = height;
}

string Shape::toString() const
{
	return "| shape: " + this->shapeName + " | height: " + to_string(this->height) + " |\n" + toStringSpecific() + "\n";
}