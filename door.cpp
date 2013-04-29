#include "door.h"

using namespace std;

Door::Door()
{
	pixMap1 = new QPixmap("images/doorclosed.png");
	pixMap2 = new QPixmap("images/dooropen.png");
	setPixmap(*pixMap1);
	x = 550;
	y = 150;
	setPos(x, y);
	isOpen = false;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Door::~Door()
{

}

Door::Door(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

/*
void Door::go()
{
	timer->start();
}
*/

void Door::move()
{
//implement move
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
}
