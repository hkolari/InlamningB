#ifndef BOX_H
#define BOX_H
#include "Shape.h"


class Box: public Shape
{
private:
	//Using "B_" before the name to indicate where it originally originated from, to avoid confusion later on.
	int B_length;
	int B_width;

public:
	Box(string shapeName = "Box", int height = -1, int B_length = -1, int B_width = -1);
	Box(const Box& origObj);
	Box& operator=(const Box& origObj);
	virtual ~Box();
	int getB_length() const;
	int getB_width() const;
	int getB_volume() const;

	void setB_length(int b_length);
	void setB_width(int B_width);
	string toStringSpecific() const;

};

#endif // !BOX_H
