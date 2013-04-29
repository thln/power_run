#include "battery.h"

using namespace std;

/** Constructor */
battery::battery()
{
	pixMap1 = new QPixmap("images/battery.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 10;
	setPos(x, y);
	type = 4;
	left = true;
	isOpen = false;

}

/** Destructor */
battery::~battery()
{
	delete pixMap1;
}


/** Returns type */
int battery::getType()
{
	return type;
}

/** Move */
void battery::move()
{
//implement move

	if(!isOpen)
	{
	int num = counter%700;
	 x = num;
	 isOpen = true;
	}

		vX = 0;
		vY = 1;
		x += vX;
		y += vY;
		setPos(x, y);

counter++;
}
