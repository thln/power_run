#include "father.h"

using namespace std;

Father::Father()
{
//	pixMap1 = new QPixmap("testmom1.png");
//	pixMap2 = new QPixmap("testmom2.png");
//	setPixmap(*pixMap1);
	x = 550;
	y = 300;
	setPos(x, y);
	left = true;

	timer = new QTimer();
	timer->setInterval(50);
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

Father::~Father()
{

}

Father::Father(QPixmap *p, int nx, int ny) //: Thing ( p, nx, ny)
{


}

void Father::go()
{
	timer->start();
}

void Father::move()
{
//implement move

}
