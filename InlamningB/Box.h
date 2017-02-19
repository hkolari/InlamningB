#ifndef BOX_H
#define BOX_H
#include "Shape.h"

class Box: public Shape
{
private:
	//Using "B_" before the name to indicate where it originally originated from, to avoid confusion later on.
	int B_length;
	int B_width;
	int B_height;

public:
	Box(string shapeName = "Box", int B_length = -1, int B_width = -1, int b_height = -1);
	virtual ~Box();
	int getB_length() const;
	int getB_width() const;
	int getB_height() const;
	string toStringAsBox() const;

};

#endif // !BOX_H
