#include"Box.h"
#include"Cone.h"
#include"ShapeRegister.h"
#include<iostream>
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//1. Creating an object, using ShapeRegister(CAPACITY == 2)
	cout << "-----------------------------------------" << endl;
	ShapeRegister* myRegister = new ShapeRegister(2);

	//2. Adding 1 cone and 1 box
	cout << "-----------------------------------------" << endl;
	myRegister->addCone("Test1", 1, 1.1); //Cone(Name, height, radius)
	myRegister->addBox("Test2", 2, 2, 2); //Box(Name, height, length, width)


	// SHOW MY SHAPE AS STRING
	int arrCapacity = 2;
	string *stringArr = new string[arrCapacity];

	myRegister->getAllShapesAsString(stringArr, arrCapacity);

	for (int i = 0; i < myRegister->nrOfShapes(); i++)
	{
		cout << stringArr[i] << endl;
	}

	//3. Adding an additional shape so that it will expand (expands by 2)!
	cout << "-----------------------------------------" << endl;
	myRegister->addCone("Test3", 3, 3.3);

	//4. Deletes a shape that does not exist.
	cout << "-----------------------------------------" << endl;
	myRegister->removeShape(99); //Tries to remove shape with the height value of 99.

	//5. Deletes a shape that does exist.
	cout << "-----------------------------------------" << endl;
	myRegister->removeShape(1); //Tries to remove shape with the height value of 1

	//6. Deletes the remaining 2 shapes.
	cout << "-----------------------------------------" << endl;
	myRegister->removeShape(3);
	myRegister->removeShape(2);

	//7. Add two additional shapes.
	cout << "-----------------------------------------" << endl;
	myRegister->addBox("Test4", 4, 4, 4);
	myRegister->addCone("Test5", 5, 5.5);

	//TODO: 8. Edit content.
	cout << "-----------------------------------------" << endl;


	//9.Test of copy constructor and "tilldelning" operator. Also check memory leaks!
	cout << "-----------------------------------------" << endl;
	//ShapeRegister test10 = *myRegister; //test for copy constructor
	ShapeRegister test10(*myRegister); //test for copy constructor

	test10.addBox("TestBox", 10, 10, 10);
	
	ShapeRegister test11; //test for "tilldelnings" operator
	test11 = *myRegister;

	getchar();
	delete myRegister;
	return 0;
}