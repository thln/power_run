#include "anvil.h"

using namespace std;

/** Constructor */
Anvil::Anvil()
{
	pixMap1 = new QPixmap("images/anvil.png");
	setPixmap(*pixMap1);
	x = 10;
	y = 10;
	type = 6;
	isOpen = false;
	setPos(x, y);
	left = true;

}

/** Destructor */
Anvil::~Anvil()
{

}


/** Returns type */
int Anvil::getType()
{
	return type;
}

/** Move */
void Anvil::move()
{
	//implement move
//	if(isOpen)
//	{
//		vX = 0;
		vY = 1;
//		x += vX;
		y += vY;
//		std::cout<< y <<std::endl;
		setY(y);
//	}
//	counter++;
}

/**Makes everything faster */
void Anvil::faster()
{
	vX = vX*2;
	vY = vY*2;

}

