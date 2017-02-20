#include "Box.h"


Box::Box(string shapeName, int height, int B_length, int B_width)
	:Shape(shapeName, height)
{
	this->B_length = B_length;
	this->B_width = B_width;
}

Box::Box(const Box& origObj)
	:Shape(origObj)
{
	this->B_length = origObj.B_length;
	this->B_width = origObj.B_width;
}

Box& Box::operator=(const Box& origObj)
{
	operator=(origObj);
	this->B_length = origObj.B_length;
	this->B_width = origObj.B_width;
	return *this;
}

Box::~Box()
{
}

int Box::getB_length() const
{
	return this->B_length;
}

int Box::getB_width() const
{
	return this->B_width;
}

void Box::setB_length(int b_length)
{
	this->B_length = b_length;
}

void Box::setB_width(int B_width)
{
	this->B_width = B_width;
}

string Box::toStringSpecific() const
{
	return "| length: " + to_string(this->B_length) + " | width: " + to_string(this->B_width) + " |\n";
}
