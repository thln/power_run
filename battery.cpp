#include "battery.h"

using namespace std;

battery::battery()
{
	pixMap1 = new QPixmap("images/battery.png");
//	pixMap2 = new QPixmap("testmom2.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 10;
	setPos(x, y);
	type = 4;
	left = true;
	isOpen = false;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

battery::~battery()
{
	delete pixMap1;
}

battery::battery(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

/*
void battery::go()
{
	timer->start();
}
*/

int battery::getType()
{
	return type;
}

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
