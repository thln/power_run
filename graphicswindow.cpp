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

void GraphicsWindow::setPlayer(string name)
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
}

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
