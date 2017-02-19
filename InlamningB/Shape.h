#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape
{
private:
	string shapeName;

public:
	Shape(string shapeName);
	Shape();
	Shape(const Shape& origObj);
	Shape& operator=(const Shape& origObj);
	virtual ~Shape();
	string getShapeName() const;
	string toString() const;
	virtual string toStringSpecific() const = 0;
};

#endif // !SHAPE_H
