#include "mainplayer.h"


using namespace std;

/** Constructor */
MainPlayer::MainPlayer()
{

}

/** Constructor */
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

/** Destructor */
MainPlayer::~MainPlayer()
{
	timer->stop();
	delete pic;
	delete picduck;
	delete nameID;
}

/** Velocity Setter */
void MainPlayer::setVelocity(double x, double y)
{
	velocityX = x;
	velocityY = y;
}

/** starts timer to jump*/
void MainPlayer::movejump()
{
	timer->start();
}

/** Nothing */
void MainPlayer::setFloor()
{
	floor = positionY;
}

/** Nothing */
void MainPlayer::resetFloor()
{
	floor = 300;
}

/** checks if jumping */
void MainPlayer::jumpCheck()
{
if(positionY == floor)
{
	jumping = false;
//	cout << "LALA" << endl;
	timer->stop();
}
}

/** Velocity Setter */
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

/** Velocity Setter*/
void MainPlayer::setVelocityY(double y)
{
	velocityY = y;
}

/** Returns name */
QString MainPlayer::getName()
{
	return name_;
}

/** jump */
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

/** Ducking */
void MainPlayer::moveduck()
{
	ducking = true;
	setPixmap(*picduck);

}

/** flinching */
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
