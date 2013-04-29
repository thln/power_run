#ifndef STARTSCREENWINDOW_H
#define STARTSCREENWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "openingscreen.h"

using namespace std;

/**
	* This class is used to keep track of startwindow.
	* Inherits from QGraphicsView.
	* @author Tam Henry Le Nguyen */

class startScreenWindow : public QGraphicsView
{
	Q_OBJECT

	public:
		startScreenWindow(); /** Constructor */
		~startScreenWindow(); /** Destructor */

	private:
 QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view; /** the view */

};

#endif
