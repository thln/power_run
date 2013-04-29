#include "door.h"

using namespace std;

/** Constructor */
Door::Door()
{
	pixMap1 = new QPixmap("images/doorclosed.png");
	pixMap2 = new QPixmap("images/dooropen.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 150;
	setPos(x, y);
	type = 3;
	isOpen = false;

}

/** Destructor */
Door::~Door()
{
	delete pixMap1;
	delete pixMap2;
}


/** Returns type */
int Door::getType()
{
	return type;
}

/** Move */
void Door::move()
{
//implement move
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);

if(counter%600 == 0 && isOpen == false)
{	
	setPixmap(*pixMap2);
	isOpen = true;
}
//if(counter%1200 == 0)
else
{
	isOpen = false;
	setPixmap(*pixMap1);
}

counter++;
}

/**Makes everything faster */
void Door::faster()
{
	vX = vX*2;
	vY = vY*2;

}
