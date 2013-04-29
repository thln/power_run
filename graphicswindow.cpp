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

/*
		pic1 = new QPixmap("images/testbackground1.png");
	setPixmap(*pic1);
		pic2 = new QPixmap("images/testbackground2.png");
	setPixmap(*pic2);
		pic3 = new QPixmap("images/testbackground3.png");
	setPixmap(*pic3);
		pic4 = new QPixmap("images/testbackground4.png");
	setPixmap(*pic4);
		pic5 = new QPixmap("images/testbackground5.png");
	setPixmap(*pic5);
		pic6 = new QPixmap("images/testbackground6.png");
	setPixmap(*pic6);
		pic7 = new QPixmap("images/testbackground7.png");
	setPixmap(*pic7);
		pic8 = new QPixmap("images/testbackground8.png");
	setPixmap(*pic8);
		pic9 = new QPixmap("images/testbackground9.png");
	setPixmap(*pic9);
		pic10 = new QPixmap("images/testbackground10.png");
	setPixmap(*pic);
		pic11 = new QPixmap("images/testbackground11.png");
	setPixmap(*pic);
		pic12 = new QPixmap("images/testbackground12.png");
	setPixmap(*pic);
		pic13 = new QPixmap("images/testbackground13.png");
	setPixmap(*pic);
		pic14 = new QPixmap("images/testbackground14.png");
	setPixmap(*pic);
		pic15 = new QPixmap("images/testbackground15.png");
	setPixmap(*pic);
		pic16 = new QPixmap("images/testbackground16.png");
	setPixmap(*pic);
*/	
	
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

//	MyScore.push_back(scoreBox(score));



}

/** Show
	* Displays the graphicsWindow */
void GraphicsWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
	//timer->start();

    //This is how we get our view displayed.
    this->show();
}

/** getScene
	* Scene Accessor */
QGraphicsScene *GraphicsWindow::getScene()
{
	return scene;
}

void GraphicsWindow::setPlayer(QString name)
{
	Player1 = new MainPlayer(this, name);
	scene->addItem(Player1);
	isAlive = true;
}

void GraphicsWindow::deletePlayer()
{
	//	cout << "hi " << endl;
	//checks if a "game" is happening
	if(isAlive)
	{
	//	cout << "restarting" << endl;
		delete Player1;
		isAlive = false;
	}
	//	cout << "hi " << endl;
}

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
    for(int i=0; i<MyThings.size(); i++)
    {
    	delete MyThings[i];
    }   
    delete Player1;
    delete timer;
    delete scene;
}

void GraphicsWindow::update()
{
	//time_t time1;
	//time(time1);
		srand(time(NULL)* counter);
	//	srand(5000);
		int num = rand() % index;
	//	cout << num << endl;
		switch(num) 
		{
			case 1:
				MyThings.push_back(new Mother);
				scene->addItem(MyThings[MyThings.size()-1]);
	//			MyThings[index]->move();
	//			index++;
				break;
			case 2:
				MyThings.push_back(new Father);
				scene->addItem(MyThings[MyThings.size()-1]);
	//			MyThings[index]->move();
	//			index++;
				break;
			case 3:
				MyThings.push_back(new PlatformObject);
				scene->addItem(MyThings[MyThings.size()-1]);
	//			MyThings[index]->move();
	//			index++;
				break;
			case 4:
				MyThings.push_back(new Door);
				scene->addItem(MyThings[MyThings.size()-1]);
	//			MyThings[index]->move();
	//			index++;
				break;
			case 5:
				MyThings.push_back(new Dog);
				scene->addItem(MyThings[MyThings.size()-1]);
	//			MyThings[index]->move();
	//			index++;
				break;
			
		}
		for(int i=0; i<MyThings.size(); i++)
		{
	//			cout << "Hi" << endl;
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

	score += (3000/index); 
//	MyScore.push_back(scoreBox(score));
//	MyScore.pop();
}

void GraphicsWindow::startgame()
{
//	cout << "Error?" << endl;
	index = 3000;

	timer->start();

//			cout << " Sick " << endl;
//			test = new Mother;

//	cout << "Error?" << endl;

//	return;
}

void GraphicsWindow::pausegame()
{
	if(timer->isActive())
	{
		timer->stop();
	}
	else if(!timer->isActive())
	{
		timer->start();			
	}
}

QTimer *GraphicsWindow::getTimer()
{
	return timer;
}

double GraphicsWindow::getScore()
{
	return score;
}
