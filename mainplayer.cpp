#include "mainplayer.h"


using namespace std;

MainPlayer::MainPlayer()
{

}


MainPlayer::MainPlayer(GraphicsWindow *p, QString name)
{
	parent = p;
	name_ = name;

	QFont font ("Arial", 12);
	QBrush whiteBrush(Qt::white);
	nameID = new QGraphicsSimpleTextItem(name_, this);
	nameID->setFont(font);
	nameID->setBrush(whiteBrush);

	pic = new QPixmap("images/mainplayerimage.png");
	picduck = new QPixmap("images/testcharacterduck.png");	
	picflinch = new QPixmap("images/testcharacterflinch.png");	
	setPixmap(*pic);
	positionX = 100;
	positionY = 300;
	setPos(100, 300);
	floor = 300;

	jumping = false;
	ducking = false; 
	flinch = false;
//	isAlive = true;
	//velocityY = -10;
	
	timer = new QTimer();
	timer->setInterval(25);
	connect(timer, SIGNAL(timeout()), this, SLOT(jump()));
}

MainPlayer::~MainPlayer()
{
	timer->stop();
	delete pic;
	delete picduck;
	delete nameID;
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

void MainPlayer::setFloor()
{
	floor = positionY;
}

void MainPlayer::resetFloor()
{
	floor = 300;
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

void MainPlayer::move(int x)
{
	if(parent->getTimer()->isActive())
	{
		ducking = false;
		if(!flinch)
		{
			setPixmap(*pic);
		}
		if( ((positionX < 0) && x<0) || ((positionX > 700) && x>1) )
		{
	//		velocityX= -velocityX;
	//		velocityY= -velocityY;
			return;
		}	
			velocityX = x;
			positionX += velocityX;
			setPos(positionX, positionY);

		if(positionY == floor)
		{
			timer->stop();
		}
	}
}

void MainPlayer::setVelocityY(double y)
{
	velocityY = y;
}

QString MainPlayer::getName()
{
	return name_;
}

void MainPlayer::jump()
{
	if(parent->getTimer()->isActive())
	{
		ducking = false;
		if(!flinch)
		{
			setPixmap(*pic);
		}

		jumping = true;

			if( (positionX < 0) || (positionX > 700) )
			{
				velocityX= -velocityX;
		//		velocityY= -velocityY;
		//		return;
			}

			accelY = 1;
	
			velocityX += accelX;
			velocityY += accelY;
			positionX += velocityX;
			positionY += velocityY;
			setPos(positionX, positionY);
	
		if(positionY == floor)
		{
			jumping = false;
			velocityX = 0;
			timer->stop();
		}
	}
}

void MainPlayer::moveduck()
{
	ducking = true;
	setPixmap(*picduck);

}

void MainPlayer::flinching()
{
	if(!flinch)
	{
		flinch = true;
		setPixmap(*picflinch);
	}
	else if(flinch)
	{
		flinch = false;
		setPixmap(*pic);
	}

}
