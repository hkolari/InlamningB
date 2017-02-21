#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape
{
private:
	string shapeName;
	int height;

public:
	Shape(string shapeName = "EMPTY", int height = -1);
	Shape(const Shape& origObj);
	Shape& operator=(const Shape& origObj);
	virtual ~Shape();

	string getShapeName() const;
	int getHeight() const;

	//No need for setShapeName, since we don't want to change it.
	void setHeight(int height); //Unsure if we need this. Might delete later.

	string toString() const;
	virtual string toStringSpecific() const = 0;
};

#endif // !SHAPE_H
