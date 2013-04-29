#include "father.h"

using namespace std;

/** Constructor */
Father::Father()
{
	pixMap1 = new QPixmap("images/packagedad.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 225;
	type = 2;
	isOpen = false;
	setPos(x, y);
	left = true;

}

/** Destructor */ 
Father::~Father()
{
	delete pixMap1;

}

/** returns type */
int Father::getType()
{
	return type;
}


/** Move */
void Father::move()
{
//implement move
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
}

/**Makes everything faster */
void Father::faster()
{
	vX = vX*2;
	vY = vY*2;

}
