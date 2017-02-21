//Made by Henry Kolari (heko16)

#include"Box.h"
#include"Cone.h"
#include"ShapeRegister.h"
#include<iostream>
#include <crtdbg.h>

void showAllShapes(ShapeRegister *myRegister); //Shows all shapes
void showAllCones(ShapeRegister *myRegister); //Shows only cones
void showAllBoxes(ShapeRegister *myRegister); //Shows all boxes
void addCone(ShapeRegister *myRegister); //Adds a cone
void addBox(ShapeRegister *myRegister); //Adds a box
void removeShape(ShapeRegister *myRegister); //Remove a shape
void editTheCone(ShapeRegister *myRegister); //Edits a cone
void editTheBox(ShapeRegister *myRegister); //Edits a box

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ShapeRegister *myRegister = new ShapeRegister();
	int menuChoice = 0;
	int continueOrNot = 0;

	while (continueOrNot == 0)
	{
		cout << "-----------------------" << endl;
		cout << "Welcome to ShapeLibrary" << endl;
		cout << "Select an option" << endl << endl;
		cout << "1.Show All Shapes" << endl;
		cout << "2.Show All Cones" << endl;
		cout << "3.Show All Boxes" << endl;
		cout << "4.Add a Cone" << endl;
		cout << "5.Add a Box" << endl;
		cout << "6.Remove a Shape" << endl;
		cout << "7.Edit a Cone" << endl;
		cout << "8.Edit a Box" << endl;
		cout << "9.Close application" << endl;
		cout << "-----------------------" << endl;
		cin >> menuChoice; cin.ignore();

		switch (menuChoice)
		{
			case 1:
			{
				showAllShapes(myRegister);
				break;
			}

			case 2:
			{
				showAllCones(myRegister);
				break;
			}

			case 3:
			{
				showAllBoxes(myRegister);
				break;
			}

			case 4:
			{	
				addCone(myRegister);
				break;
			}

			case 5:
			{
				addBox(myRegister);
				break;
			}
			case 6:
			{
				removeShape(myRegister);
				break;
			}
			
			case 7:
			{
				editTheCone(myRegister);
				break;
			}
			case 8:
			{
				editTheBox(myRegister);
				break;
			}
			case 9:
			{
				cout << "Shutting down" << endl;
				continueOrNot = 1;
				break;
			}
			default:
			{
				cout << "Error please try again" << endl;
				break;
			}
	
		}
	}

	delete myRegister;
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
	delete[] stringArr;
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
	delete[] stringArr;
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
	delete[] stringArr;
}

/////////////////////////////////////////////////////////////
//ADD AND DELETE

void addCone(ShapeRegister *myRegister)
{
	int insertHeight = 0;
	float insertRadius = 0;
	cout << "What is the cone's height?" << endl;
	cin >> insertHeight; cin.ignore();
	cout << "What is the cone's radius?" << endl;
	cin >> insertRadius; cin.ignore();
	bool success = myRegister->addCone("Cone", insertHeight, insertRadius);
	if (!success)
	{
		cout << "Adding a cone was successful" << endl;
	}
	else
	{
		cout << "An error has accured!" << endl;
	}
}

void addBox(ShapeRegister *myRegister)
{
	int insertHeight = 0;
	int insertLength = 0;
	int insertWidth = 0;

	cout << "What is the box's height?" << endl;
	cin >> insertHeight; cin.ignore();
	cout << "What is the box's length?" << endl;
	cin >> insertLength; cin.ignore();
	cout << "What is the box's width?" << endl;
	cin >> insertWidth; cin.ignore();
	bool success = myRegister->addBox("Cone", insertHeight, insertLength, insertWidth);
	if (!success)
	{
		cout << "Adding a box was successful" << endl;
	}
	else
	{
		cout << "An error has accured!" << endl;
	}
}

void removeShape(ShapeRegister *myRegister)
{
	int insertHeight = 0;

	cout << "What is the shape's height that you want to delete?" << endl;
	cin >> insertHeight; cin.ignore();
	bool success = myRegister->removeShape(insertHeight);
	if (!success)
	{
		cout << "An error has accured!" << endl;
	}
	else
	{
		cout << "Removal of shape was successful" << endl;
	}
}

/////////////////////////////////////////////////////////////
//EDIT

void editTheCone(ShapeRegister *myRegister)
{
	int insertHeight = 0;
	float insertRadius = 0;

	cout << "What is the cone's height that you want to edit?" << endl;
	cin >> insertHeight; cin.ignore();
	cout << "What would you like to change the radius to? (decimals allowed)" << endl;
	cin >> insertRadius; cin.ignore();
	bool success = myRegister->editACone(insertHeight, insertRadius);
	if (!success)
	{
		cout << "An error has accured!" << endl;
	}
	else
	{
		cout << "Edit of the cone was successful" << endl;
	}
}

void editTheBox(ShapeRegister *myRegister)
{
	int insertHeight = 0;
	int insertTheValue = 0;
	int insertChoice = 0;

	cout << "Would you either want to \n1.Edit the box's length. \n2.Edit the box's width." << endl;
	cin >> insertChoice; cin.ignore();
	cout << "What is the box's height that you want to edit?" << endl;
	cin >> insertHeight; cin.ignore();

	if (insertChoice == 1)
	{
		cout << "What would you like to change the box's length to?" << endl;
		cin >> insertTheValue; cin.ignore();
		bool success = myRegister->editABox(insertHeight, insertTheValue, insertChoice);
		if (!success)
		{
			cout << "An error has accured!" << endl;
		}
		else
		{
			cout << "Edit of the box was successful" << endl;
		}
	}

	if (insertChoice == 2)
	{
		cout << "What would you like to change the box's width to?" << endl;
		cin >> insertTheValue; cin.ignore();
		bool success = myRegister->editABox(insertHeight, insertTheValue, insertChoice);
		if (!success)
		{
			cout << "An error has accured!" << endl;
		}
		else
		{
			cout << "Edit of the box was successful" << endl;
		}
	}
}