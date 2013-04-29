#ifndef STARTSCREENWINDOW_H
#define STARTSCREENWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include "openingscreen.h"

using namespace std;

class startScreenWindow : public QGraphicsView
{
	Q_OBJECT

	public:
		startScreenWindow();
		~startScreenWindow();

	private:
//		QPixmap *pixMap1;
 QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view;

};

#endif
