#include "mother.h"

using namespace std;

Mother::Mother()
{
	pixMap1 = new QPixmap("images/testmom1.png");
	pixMap2 = new QPixmap("images/testmom2.png");
	setPixmap(*pixMap1);
	x = 550;
	y = 300;
	setPos(x, y);
//	left = true;

//	timer = new QTimer();
//	timer->setInterval(50);
//	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Mother::~Mother()
{

}

Mother::Mother(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

/*
void Mother::go()
{
	timer->start();
}
*/

void Mother::move()
{
//if(timer%1000 = 0)
//{
//if(counter%400 == 0)
//{
//	if(left)
//	{
	setPixmap(*pixMap1);
		vX = -1;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);
//	}
/*
	else if(!left)
	{
	setPixmap(*pixMap2);
		vX = -10;
		vY = 0;
		x += vX;
		y += vY;
		setPos(x, y);	
	}		
*/
//}
//counter++;

}
