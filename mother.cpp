#include "mother.h"

using namespace std;

Mother::Mother()
{
	pixmap1 = new QPixmap("testmom1.png");
	pixmap2 = new QPixmap("testmom2.png");
	setPixmap(*pixmap1);
	x = 600;
	y = 300;
	setPos(x, y);
	left = true;

	timer = new QTimer();
	timer->setInterval(50);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Mother::~Mother()
{

}

Mother::Mother(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

void Mother::go()
{
	timer->start();
}

void Mother::move()
{
//if(timer%1000 = 0)
//{
	if(left)
	{
	setPixmap(*pixmap2);
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
	}
	else if(!left)
	{
	setPixmap(*pixmap1);
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);	
	}		
//}

}
