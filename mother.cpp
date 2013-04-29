#include "mother.h"

using namespace std;

/** Constructor */
Mother::Mother()
{
	pixMap1 = new QPixmap("images/testmom1.png");
	pixMap2 = new QPixmap("images/testmom2.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 300;
	setPos(x, y);
	type = 1;
	isOpen = false;
}

/** Destructor */
Mother::~Mother()
{
	delete pixMap1;
	delete pixMap2;
}

/** Returns type */
int Mother::getType()
{
	return type;
}

/** Move */
void Mother::move()
{

	setPixmap(*pixMap1);
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
}
