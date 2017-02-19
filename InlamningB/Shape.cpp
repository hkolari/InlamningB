#include "Shape.h"



Shape::Shape(string shapeName)
{
	this->shapeName = shapeName;
}

Shape::Shape()
{
}

Shape::Shape(const Shape& origObj)
{
	this->shapeName = origObj.shapeName;
}

Shape& Shape::operator=(const Shape& origObj)
{
	this->shapeName = origObj.shapeName;
	return *this;
}

Shape::~Shape()
{
}

string Shape::getShapeName() const
{
	return this->shapeName;
}

string Shape::toString() const
{
	return "Shape: " + this->shapeName + "\n";
}