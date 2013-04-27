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
    setSceneRect(0, 0, 640, 480);
    setWindowTitle( "Programming Assignment #5: Power Run!");
    isAlive = false;
    //view = new QGraphicsView( scene );

    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    QBrush blueBrush(Qt::blue);
    QBrush yellowBrush(Qt::yellow);
    QBrush greenBrush(Qt::green);

  	
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

void GraphicsWindow::startgame()
{
	cout << "Error?" << endl;
	index = 0;
	test = new Mother;
	MyThings.push_back(test);
//	MyThings[index] = test;
	scene->addItem(MyThings[index]);
	MyThings[index]->go();
	

	cout << "Error?" << endl;

//	return;
}
