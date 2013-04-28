#include "platformobject.h"

using namespace std;

PlatformObject::PlatformObject()
{
	pixMap1 = new QPixmap("table.png");
//	pixMap2 = new QPixmap("testmom2.png");
	setPixmap(*pixMap1);
	x = 550;
	y = 275;
	setPos(x, y);
	left = true;

	timer = new QTimer();
	timer->setInterval(50);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

PlatformObject::~PlatformObject()
{

}

PlatformObject::PlatformObject(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

void PlatformObject::go()
{
	timer->start();
}

void PlatformObject::move()
{
//implement move
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);

}
