//Made by Henry Kolari (heko16)

#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H
#include <string>
#include "Shape.h"


class ShapeRegister
{
private:
	int amountOfShapes;
	int capacity;
	Shape* *shapes;

	void expand();


public:
	ShapeRegister(int capacity = 3);
	ShapeRegister(const ShapeRegister& origObj);
	virtual ~ShapeRegister();

	bool ShapeRegister::doesItExist(int height) const;
	
	bool addCone(string shapeName, int height, float C_radius);
	bool addBox(string shapeName, int height, int length, int width);
	bool removeShape(int height);
	bool getAllShapesAsString(string arr[], int capOfArr);
	bool getAllConesAsString(string arr[], int capOfArr);
	bool getAllBoxesAsString(string arr[], int capOfArr);
	bool editACone(int height, float radius);
	bool editABox(int height, int theValue, int choice);
	int nrOfShapes() const; //Pretty much getNrOfShapes
	int nrOfCones() const;
	int nrOfBoxes() const;

	ShapeRegister &operator=(const ShapeRegister &ref);

};

#endif // !SHAPEREGISTER_H
