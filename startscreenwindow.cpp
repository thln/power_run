#include "startscreenwindow.h"

/** Constructor */
startScreenWindow::startScreenWindow()
{
    scene = new QGraphicsScene();
    setScene(scene);
    setSceneRect(0, 0, 780, 500);
    setWindowTitle( "Programming Assignment #5: Power Run!");
    setBackgroundBrush(QImage("images/testbackground.png"));
	setCacheMode(QGraphicsView::CacheBackground);
	
	scene->addItem(new openingScreen);

}

/** Destructor */
startScreenWindow::~startScreenWindow()
{
	delete scene;
}
