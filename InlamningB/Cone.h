#ifndef CONE_H
#define CONE_H
#include "Shape.h"

class Cone: public Shape
{
private:
	//Using "C_" before the name to indicate where it originally originated from, to avoid confusion later on.
	float C_radius;
	int C_height;

public:
	Cone(string shapeName = "Cone", float C_radius = -1, int C_height = -1);
	Cone(const Cone& origObj);
	Cone& operator= (const Cone& origObj);
	virtual ~Cone();
	float getC_radius() const;
	int getC_height() const;
	string toStringAsCone() const;
};

#endif // !CONE_H