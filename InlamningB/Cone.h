#ifndef CONE_H
#define CONE_H
#include "Shape.h"

class Cone: public Shape
{
private:
	//Using "C_" before the name to indicate where it originally originated from, to avoid confusion later on.
	float C_radius;

public:
	Cone(string shapeName = "Cone", int height = -1, float C_radius = -1);
	Cone(const Cone& origObj);
	Cone& operator= (const Cone& origObj);
	virtual ~Cone();
	float getC_radius() const;
	void setC_radius(float C_radius);
	string toStringSpecific() const;
};

#endif // !CONE_H