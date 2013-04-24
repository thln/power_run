#include "mainplayer.h"

using namespace std;

MainPlayer::MainPlayer()
{

}


MainPlayer::MainPlayer(GraphicsWindow *p, string name)
{
	parent = p;
	name_ = name;

	pic = new QPixmap("&:/images/mainplayerimage.png");
	setPixmap(*pic);
	setPos(100, 100);
}

MainPlayer::~MainPlayer()
{

}

void MainPlayer::setVelocity(double x, double y)
{
	velocityX = x;
	velocityY = y;
}
