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

	//1. Creating an object, using ShapeRegister(CAPACITY == 2)
	cout << "1-----------------------------------------" << endl;
	ShapeRegister* myRegister = new ShapeRegister(2);

	//2. Adding 1 cone and 1 box
	cout << "2-----------------------------------------" << endl;
	myRegister->addCone("Test1", 1, 1.1); //Cone(Name, height, radius)
	myRegister->addBox("Test2", 2, 2, 2); //Box(Name, height, length, width)
	showAllShapes(myRegister);
	//showAllCones(myRegister); 
	//showAllBoxes(myRegister);

	//3. Adding an additional shape so that it will expand (expands by 2)!
	cout << "3-----------------------------------------" << endl;
	myRegister->addCone("Test3", 3, 3.3);
	showAllShapes(myRegister);

	//4. Deletes a shape that does not exist.
	cout << "4-----------------------------------------" << endl;
	myRegister->removeShape(99); //Tries to remove shape with the height value of 99.
	showAllShapes(myRegister);

	//5. Deletes a shape that does exist.
	cout << "5-----------------------------------------" << endl;
	myRegister->removeShape(1); //Tries to remove shape with the height value of 1
	showAllShapes(myRegister);

	//6. Deletes the remaining 2 shapes.
	cout << "6-----------------------------------------" << endl;
	myRegister->removeShape(3);
	myRegister->removeShape(2);
	showAllShapes(myRegister);

	//7. Add two additional shapes.
	cout << "7-----------------------------------------" << endl;
	myRegister->addBox("Test4", 4, 4, 4);
	myRegister->addCone("Test5", 5, 5.5);
	showAllShapes(myRegister);

	//TODO: 8. Edit content.
	cout << "8-----------------------------------------" << endl;
	myRegister->editABox(4, 99, 1); //(height, theValue, choice). Choice = 1: Edits length. Choice = 2: Edits width.
	myRegister->editACone(5, 88.88); //(height, radius)
	showAllShapes(myRegister);

	//9.Test of copy constructor and "tilldelning" operator. Also check memory leaks!
	cout << "9-----------------------------------------" << endl;
	//ShapeRegister test10 = *myRegister; //test for copy constructor
	ShapeRegister test10(*myRegister); //test for copy constructor

	test10.addBox("TestBox", 10, 10, 10);
	ShapeRegister test11; //test for "tilldelnings" operator
	test11 = *myRegister;

	getchar();
	delete myRegister;
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