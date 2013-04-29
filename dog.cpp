#include "dog.h"

using namespace std;

Dog::Dog()
{
	pixMap1 = new QPixmap("images/dog.png");
//	pixMap2 = new QPixmap("testmom2.png");
	setPixmap(*pixMap1);
	x = 0;
	y = 350;
	type = 5;
	isOpen = false;
	setPos(x, y);
	left = true;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Dog::~Dog()
{

}

Dog::Dog(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

/*
void Dog::go()
{
	timer->start();
}
*/

int Dog::getType()
{
	return type;
}

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
