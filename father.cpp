#include "father.h"

using namespace std;

Father::Father()
{
	pixMap1 = new QPixmap("images/packagedad.png");
//	pixMap2 = new QPixmap("testmom2.png");
	setPixmap(*pixMap1);
	x = 700;
	y = 225;
	type = 2;
	isOpen = false;
	setPos(x, y);
	left = true;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Father::~Father()
{
	delete pixMap1;

}

int Father::getType()
{
	return type;
}

Father::Father(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

/*
void Father::go()
{
	timer->start();
}
*/

void Father::move()
{
//implement move
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
}
