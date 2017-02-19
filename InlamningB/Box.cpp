#include "Box.h"



Box::Box(string shapeName, int B_length, int B_width, int b_height)
	:Shape(shapeName)
{
	this->B_length = B_length;
	this->B_width = B_width;
	this->B_height = B_height;
}

Box::Box(const Box& origObj)
	:Shape(origObj)
{
	this->B_length = origObj.B_length;
	this->B_width = origObj.B_width;
	this->B_height = origObj.B_height;
}

Box& Box::operator=(const Box& origObj)
{
	Shape::operator=(origObj);
	this->B_length = origObj.B_length;
	this->B_width = origObj.B_width;
	this->B_height = origObj.B_height;
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

int Box::getB_height() const
{
	return this->B_height;
}

string Box::toStringAsBox() const
{
	return "| length: " + to_string(this->B_length) + " | width: " + to_string(this->B_width) + " | height: " + to_string(this->B_height) + " |\n";
}
