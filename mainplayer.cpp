#include "mainplayer.h"

using namespace std;

MainPlayer::MainPlayer()
{

}


MainPlayer::MainPlayer(GraphicsWindow *p, string name)
{
	parent = p;
	name_ = name;

	pic = new QPixmap("mainplayerimage.png");
	setPixmap(*pic);
	positionX = 100;
	positionY = 240;
	setPos(100, 240);
}

MainPlayer::~MainPlayer()
{

}

void MainPlayer::setVelocity(double x, double y)
{
	velocityX = x;
	velocityY = y;
}

void MainPlayer::move(int x, int y)
{
	velocityX = x;
	velocityY = y;
	positionX += velocityX;
	positionY += velocityY;
	setPos(positionX, positionY);
}
