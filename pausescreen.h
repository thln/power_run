#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class pauseScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		pauseScreen();
		~pauseScreen();

	
	private:
		QPixmap *pixMap1;
		int x;
		int y;

};

#endif
