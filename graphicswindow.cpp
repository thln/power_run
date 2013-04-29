#include "graphicswindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Nothing */
void GraphicsWindow::handleTimer() {

counter++;

if(counter == 100)
{
	timer->stop();
}

}

//clicking will make the timer stop or start
/** Nothing */
void GraphicsWindow::clicker()
{
}

/** Default Constructor*/
GraphicsWindow::GraphicsWindow()  {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    setScene(scene);
    //640 480
    setSceneRect(0, 0, 780, 500);
    setWindowTitle( "Programming Assignment #5: Power Run!");
    isAlive = false;
    invincible = false;
    lastcase = 0;
    //view = new QGraphicsView( scene );

    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    QBrush blueBrush(Qt::blue);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);

	timer = new QTimer();
	timer->setInterval(5);
  	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  	counter = 0;


//adding pictures in for animation
	imageindex = 0;

	
	MyBackground.push_back(QImage("images/testbackground1.png"));
	MyBackground.push_back(QImage("images/testbackground2.png"));
	MyBackground.push_back(QImage("images/testbackground3.png"));
	MyBackground.push_back(QImage("images/testbackground4.png"));
	MyBackground.push_back(QImage("images/testbackground5.png"));
	MyBackground.push_back(QImage("images/testbackground6.png"));
	MyBackground.push_back(QImage("images/testbackground7.png"));
	MyBackground.push_back(QImage("images/testbackground8.png"));
	MyBackground.push_back(QImage("images/testbackground9.png"));
	MyBackground.push_back(QImage("images/testbackground10.png"));
	MyBackground.push_back(QImage("images/testbackground11.png"));
	MyBackground.push_back(QImage("images/testbackground12.png"));
	MyBackground.push_back(QImage("images/testbackground13.png"));
	MyBackground.push_back(QImage("images/testbackground14.png"));
	MyBackground.push_back(QImage("images/testbackground15.png"));
	MyBackground.push_back(QImage("images/testbackground16.png"));
	

	lives = 5;
	score = 0;
	flinchcount = 0;
	batteryOn = false;

}

/** Show
	* Displays the graphicsWindow */
void GraphicsWindow::show() 
{
    //This is how we get our view displayed.
    this->show();
}

/** getScene
	* Scene Accessor */
QGraphicsScene *GraphicsWindow::getScene()
{
	return scene;
}

/** Makes a player */
void GraphicsWindow::setPlayer(QString name)
{
	Player1 = new MainPlayer(this, name);
	scene->addItem(Player1);
	isAlive = true;
}

/** Delete Player if necessary */
void GraphicsWindow::deletePlayer()
{

	if(isAlive)
	{
		timer->stop();
		delete Player1;
		
			lives = 5;
			score = 0;
			flinchcount = 0;
			invincible = false;
			lastcase = 0;
			counter = 0;		
		
		isAlive = false;
		
		
	}
}

/** Returns player */
MainPlayer *GraphicsWindow::getPlayer()
{
	return Player1;
}

/** Destructor */
GraphicsWindow::~GraphicsWindow()
{
    timer->stop();
    //delete MyThings;
    //delete MyBackground;
    for(unsigned int i=0; i<MyThings.size(); i++)
    {
    	delete MyThings[i];
    }   
    delete Player1;
    delete timer;
    delete scene;
}

/** Update everything */
void GraphicsWindow::update()
{
		srand(time(NULL)* counter);
		int num = rand() % index;
		switch(num) 
		{
			case 1:
				if(lastcase > 5)
				{
				MyThings.push_back(new Mother);
				scene->addItem(MyThings[MyThings.size()-1]);
				}
				break;
			case 2:
				if(lastcase > 5)
				{
				MyThings.push_back(new Father);
				scene->addItem(MyThings[MyThings.size()-1]);
				}
				break;
			case 3:
				if(lastcase > 5)
				{
				MyThings.push_back(new battery);
				scene->addItem(MyThings[MyThings.size()-1]);
				}
				break;
			case 4:
				if(lastcase > 5)
				{
				MyThings.push_back(new Door);
				scene->addItem(MyThings[MyThings.size()-1]);
				}
				break;
			case 5:
				MyThings.push_back(new Dog);
				scene->addItem(MyThings[MyThings.size()-1]);
				break;
			
		}
		lastcase = num;
		for(unsigned int i=0; i<MyThings.size(); i++)
		{
				MyThings[i]->move();	
		}

	counter++;

	if(counter == 1000)
	{
		index = index-100;
		counter = 0;
	}

	if(counter%10 == 0)
	{
		setBackgroundBrush(MyBackground[imageindex]);
		setCacheMode(QGraphicsView::CacheBackground);
	
		imageindex++;
		if( imageindex == MyBackground.size())
		{
			imageindex = 0;
		}
	}	
	
	//onTable = false;
	//checking for collisions
	for(unsigned int i=0; i< MyThings.size(); i++)
	{
		Thing* item = MyThings[i];
		if(Player1->collidesWithItem(item) && !invincible)
		{
			//Mom
			if(item->getType() == 1)
			{
				lives--;
				Player1->flinching();
				invincible = true;
			}
			//Father
			if(item->getType() == 2)
			{
				if(!Player1->ducking)
				{
					lives--;
					Player1->flinching();
					invincible = true;
				}
			}
			//Door
			if(item->getType() == 3)
			{
				if(item->isOpen)
				{
					lives--;
					Player1->flinching();
					invincible = true;
				}
			}
			//Battery
			if(item->getType() == 4)
			{
				invincible = true;
				batteryOn = true;
				lives++;
				score+= 1000;
			}
			//Dog
			if(item->getType() == 5)
			{
				lives--;
				Player1->flinching();
				invincible = true;
			}		
		
		}
	}
	
	
	//if invincible or just hit
	if(invincible)
	{
		flinchcount++;
	}
	//approx 300 counts, then character is vulnerable again
	if(flinchcount == 300)
	{
		invincible = false;
		if(!batteryOn)
		{
		Player1->flinching();
		}
		batteryOn = false;
		flinchcount = 0;
	}


	score += (3000/index); 
	if(lives == 0)
	{
		scene->addItem(new closingScreen);
		timer->stop();	
	}
}

/** Start Game */
void GraphicsWindow::startgame()
{
	index = 3000;
	score = 0; 
	lives = 5;

	timer->start();

//	return;
}

/** pauses game */
void GraphicsWindow::pausegame()
{
	if(lives != 0)
	{
		if(timer->isActive())
		{
			pause = new pauseScreen;
			scene->addItem(pause);
			timer->stop();
		}
		else if(!timer->isActive())
		{
			scene->removeItem(pause);
			timer->start();			
		}
	}
}

/** returns timer */
QTimer *GraphicsWindow::getTimer()
{
	return timer;
}

/** returns score */
double GraphicsWindow::getScore()
{
	return score;
}

/** returns lives */
int GraphicsWindow::getLife()
{
	return lives;
}
