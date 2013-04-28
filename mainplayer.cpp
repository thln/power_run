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
	floor = 300;

	jumping = false;
//	isAlive = true;
	//velocityY = -10;
	
	timer = new QTimer();
	timer->setInterval(25);
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

void MainPlayer::movejump()
{
	timer->start();
}

void MainPlayer::jumpCheck()
{
if(positionY == floor)
{
	jumping = false;
//	cout << "LALA" << endl;
	timer->stop();
}
}

void MainPlayer::move(int x, int y)
{
//	std::cout << x << std::endl;
	if( ((positionX < 0) && x<0) || ((positionX > 600) && x>1) )
	{
//		velocityX= -velocityX;
//		velocityY= -velocityY;
		return;
	}	
		velocityX = x;
		velocityY = y;
		positionX += velocityX;
		positionY += velocityY;
//		cout << "X,Y " << positionX << " " << positionY << endl;
		setPos(positionX, positionY);

	if(positionY == floor)
	{
//		cout << "LALA" << endl;
		timer->stop();
	}

}

void MainPlayer::setVelocityY(double y)
{
	velocityY = y;
}

string MainPlayer::getName()
{
	return name_;
}

void MainPlayer::jump()
{
jumping = true;

//why doesn't jump work?
	if( (positionX < 0) || (positionX > 600) )
	{
		velocityX= -velocityX;
//		velocityY= -velocityY;
//		return;
	}

//	velocityY = -5;
	accelY = 1;
//	floor = positionY;
	
//do{
//	if(counter%10 == 0)
//	{
//for(int i=0; i<19; i++)
//{
	velocityX += accelX;
	velocityY += accelY;
//	cout << velocityY << endl;
	positionX += velocityX;
	positionY += velocityY;
//	cout << positionY << endl;
	setPos(positionX, positionY);
//}
//	velocityY = -10;
//	}
//	counter++;	
//}while(positionY != floor);
if(positionY == floor)
{
	jumping = false;
	velocityX = 0;
//	cout << "LALA" << endl;
	timer->stop();
}

}
