#include "ShapeRegister.h"
#include "Cone.h"
#include "Box.h"


void ShapeRegister::expand()
{
	this->capacity += 2;
	Shape* *temp = new Shape*[this->capacity];
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		temp[i] = this->shapes[i];
	}
	delete[] this->shapes;
	this->shapes = temp;
}

ShapeRegister::ShapeRegister(int capacity)
{
	this->amountOfShapes = 0;
	this->capacity = capacity;
	this->shapes = new Shape*[this->capacity];
}

ShapeRegister::ShapeRegister(const ShapeRegister& origObj)
{
	
	this->amountOfShapes = origObj.amountOfShapes;
	this->capacity = origObj.capacity;
	this->shapes = new Shape*[origObj.capacity];	

	Box* aBoxPtr = nullptr;
	Cone* aConePtr = nullptr;
	for (int i = 0; i < origObj.amountOfShapes; i++)
	{
		//TODO: Might be some bugs here. Unsure if I did right.
		aBoxPtr = dynamic_cast<Box*>(origObj.shapes[i]);
		if (aBoxPtr != nullptr)
		{
			this->shapes[i] = new Box(*aBoxPtr);
		}
		else
		{
			aConePtr = dynamic_cast<Cone*>(origObj.shapes[i]);
			this->shapes[i] = new Cone(*aConePtr);
		}
	}
}

ShapeRegister & ShapeRegister::operator=(const ShapeRegister & ref) //Quite similiar to copy constructor
{

	this->amountOfShapes = ref.amountOfShapes;
	this->capacity = ref.capacity;

	delete[] this->shapes; // To copy a value from ref.shapes, we have to first take away the establish values.

	this->shapes = new Shape*[ref.capacity]; // vi ser till att "this->shapes" är en array med storleken av ref.capacity
	Box* aBoxPtr = nullptr;		//Preparing for dynamic_cast
	Cone* aConePtr = nullptr;

	for (int i = 0; i < ref.amountOfShapes; i++)
	{
		aBoxPtr = dynamic_cast<Box*>(ref.shapes[i]);

		if (aBoxPtr != nullptr)
		{
			this->shapes[i] = new Box(*aBoxPtr);
		}
		else
		{
			aConePtr = dynamic_cast<Cone*>(ref.shapes[i]);
			this->shapes[i] = new Cone(*aConePtr);
		}
	}

	return *this;
}


///////////////////////////////////////////////////////////////////////

//ADD, DELETE and DOES IT EXIST

//Checks if the shape already exists by using and comparing height.
bool ShapeRegister::doesItExist(int height) const
{
	bool existance = false;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHeight() == height)
		{
			existance = true; //If true, it exists.
		}
	}
	return existance;
}

//Adds the cone.
bool ShapeRegister::addCone(string shapeName, int height, float C_radius)
{
	bool existance = doesItExist(height);
	if(!existance)
	{
		if (this->amountOfShapes == this->capacity)
		{
			this->expand();
		}
		this->shapes[this->amountOfShapes++] = new Cone(shapeName, height, C_radius);
	}
	return existance;
}

//Adds the box.

bool ShapeRegister::addBox(string shapeName, int height, int length, int width)
{
	bool existance = doesItExist(height);
	if (!existance)
	{
		if (this->amountOfShapes == this->capacity)
		{
			this->expand();
		}
		this->shapes[this->amountOfShapes++] = new Box(shapeName, height, length, width);
	}
	return existance;
}

bool ShapeRegister::removeShape(int height)
{
	bool removed = false;
	if (this->doesItExist(height)) //If it returns true, that means it exists and needs to be removed.
	{
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			if (this->shapes[i]->getHeight() == height)
			{
				delete shapes[i];
				shapes[i] = shapes[amountOfShapes - 1]; //Moves last array to the current array location.
				this->shapes[amountOfShapes - 1] = nullptr; //Last place of the array will be erased/cleaned.
				removed = true;
				amountOfShapes--;
			}
		}
	}
	
	return removed;
}

///////////////////////////////////////////////////////////////////////
//EDIT AND STUFF
//(I presume you are not allowed to edit the height)

bool ShapeRegister::editACone(int height, int C_radius)
{
	bool edited = false;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHeight() == height)
		{
			Cone* aConePtr = nullptr;
			
			aConePtr = dynamic_cast<Cone*>(this->shapes[i]);

			if (aConePtr != nullptr)
			{
				aConePtr->setC_radius(C_radius);
				edited = true;
			}
		}
	}
	return edited;
}

bool ShapeRegister::editABox(int height, int theValue, int choice)
{
	bool edited = false;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHeight() == height)
		{
			Box* aBoxPtr = nullptr;

			aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);

			if (aBoxPtr != nullptr)
			{
				if (choice = 1)
				{
					aBoxPtr->setB_length(theValue);
					edited = true;
				}
				if (choice = 2)
				{
					aBoxPtr->setB_width(theValue);
					edited = true;
				}
			}
		}
	}
	return edited;
}





///////////////////////////////////////////////////////////////////////


ShapeRegister::~ShapeRegister()
{
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		delete this->shapes[i];
	}

	delete[] this->shapes;
}

//TO STRING AND STUFF

bool ShapeRegister::getAllShapesAsString(string arr[], int capOfArr)
{
	bool filled = false;
	if (capOfArr >= this->amountOfShapes)
	{
		for (int i = 0; i < this->nrOfShapes(); i++)
		{
			arr[i] = this->shapes[i]->toString();
		}
		filled = true;
	}
	return filled;
}

bool ShapeRegister::getAllConesAsString(string arr[], int capOfArr)
{
	bool filled = false;
	Cone* aConePtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aConePtr = dynamic_cast<Cone*>(this->shapes[i]);
		if (aConePtr != nullptr)
		{
			arr[i] = this->shapes[i]->toString();
		}
		filled = true;
	}
	return filled;
}

bool ShapeRegister::getAllBoxesAsString(string arr[], int capOfArr)
{
	bool filled = false;
	Box* aBoxPtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);
		if (aBoxPtr != nullptr)
		{
			arr[i] = this->shapes[i]->toString();
		}
		filled = true;
	}
	return filled;
}


//NUMBER OF THIS AND THAT

int ShapeRegister::nrOfShapes() const
{
	return this->amountOfShapes;
}

int ShapeRegister::nrOfCones() const
{
	int coneCounter = 0;
	Cone* aConePtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aConePtr = dynamic_cast<Cone*>(this->shapes[i]);
		if (aConePtr != nullptr)
		{
			coneCounter++;
		}
	}
	return coneCounter;
}

int ShapeRegister::nrOfBoxes() const
{
	int boxCounter = 0;
	Box* aBoxPtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);
		if (aBoxPtr != nullptr)
		{
			boxCounter++;
		}
	}
	return boxCounter;
}