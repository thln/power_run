#include "door.h"

using namespace std;

Door::Door()
{
	pixMap1 = new QPixmap("images/doorclosed.png");
	pixMap2 = new QPixmap("images/dooropen.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 150;
	setPos(x, y);
	isOpen = false;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Door::~Door()
{
	delete pixMap1;
	delete pixMap2;
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

if(counter%600 == 0)
{	
	isOpen = true;
	setPixmap(*pixMap2);
}
if(counter%1201 == 0)
{
	isOpen = false;
	setPixmap(*pixMap1);
}

counter++;
}
