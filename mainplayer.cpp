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
	positionY = 300;
	setPos(100, 300);

	velocityY = -10;
	
	timer = new QTimer();
	timer->setInterval(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(jump()));
}

MainPlayer::~MainPlayer()
{
	timer->stop();
}

void MainPlayer::setVelocity(double x, double y)
{
	velocityX = x;
	velocityY = y;
}

void MainPlayer::move(int x, int y)
{
//	std::cout << x << std::endl;
	if( ((positionX < 0) && x<0) || ((positionX > 600) && x>1) )
	{
		return;
	}	
		velocityX = x;
		velocityY = y;
		positionX += velocityX;
		positionY += velocityY;
//		cout << "X,Y " << positionX << " " << positionY << endl;
		setPos(positionX, positionY);
}

void MainPlayer::setVelocityY(double y)
{
	velocityY = y;
}

void MainPlayer::jump()
{
//why doesn't jump work?
	if( (positionX < 0) || (positionX > 600) )
	{
		return;
	}

//	velocityY = -10;
	accelY = 1;
	floor = positionY;
//do{
//	if(counter%10 == 0)
//	{
	velocityX += accelX;
	velocityY += accelY;
	cout << velocityY << endl;
	positionX += velocityX;
	positionY += velocityY;
	cout << positionY << endl;
	setPos(positionX, positionY);
//	}
	counter++;	
//}while(positionY != floor);
if(positionY == floor)
{
	timer->stop();
}

}
