#include "dog.h"

using namespace std;

/** Constructor */
Dog::Dog()
{
	pixMap1 = new QPixmap("images/dog.png");
	setPixmap(*pixMap1);
	x = 0;
	y = 350;
	type = 5;
	isOpen = false;
	setPos(x, y);
	left = true;

}

/** Destructor */
Dog::~Dog()
{

}


/** Returns type */
int Dog::getType()
{
	return type;
}

/** Move */
void Dog::move()
{
	//implement move
	
	if(counter> 1000)
	{
		vX = 2;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
	
	}
	counter++;
}
