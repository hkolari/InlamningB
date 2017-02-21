#include"Box.h"
#include"Cone.h"
#include"ShapeRegister.h"
#include<iostream>
#include <crtdbg.h>

void showAllShapes(ShapeRegister *myRegister); //Shows all shapes
void showAllCones(ShapeRegister *myRegister); //Shows only cones
void showAllBoxes(ShapeRegister *myRegister); //Shows all boxes

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ShapeRegister* myRegister;
	


	getchar();
	return 0;
}

/////////////////////////////////////////////////////////////

//All my ShowAll functions are below!

void showAllShapes(ShapeRegister *myRegister)
{
	// SHOW MY SHAPES AS STRING

	int arrCapacity = 0;
	if (myRegister->nrOfShapes() == 0)
	{
		arrCapacity = 1;
	}
	else
	{
		arrCapacity = myRegister->nrOfShapes();
	}

	string *stringArr = new string[arrCapacity];
	myRegister->getAllShapesAsString(stringArr, arrCapacity);

	for (int i = 0; i < myRegister->nrOfShapes(); i++)
	{
		cout << stringArr[i];
	}
}

void showAllCones(ShapeRegister *myRegister)
{
	// SHOW MY CONES AS STRING
	int arrCapacity = 0;
	if (myRegister->nrOfShapes() == 0)
	{
		arrCapacity = 1;
	}
	else
	{
		arrCapacity = myRegister->nrOfShapes();
	}
	string *stringArr = new string[arrCapacity];

	myRegister->getAllConesAsString(stringArr, arrCapacity);

	for (int i = 0; i < myRegister->nrOfShapes(); i++)
	{
		cout << stringArr[i];
	}
}

void showAllBoxes(ShapeRegister *myRegister)
{
	// SHOW MY BOXES AS STRING
	int arrCapacity = 0;
	if (myRegister->nrOfShapes() == 0)
	{
		arrCapacity = 1;
	}
	else
	{
		arrCapacity = myRegister->nrOfShapes();
	}
	string *stringArr = new string[arrCapacity];

	myRegister->getAllBoxesAsString(stringArr, arrCapacity);

	for (int i = 0; i < myRegister->nrOfShapes(); i++)
	{
		cout << stringArr[i];
	}
}