#ifndef OPENINGSCREEN_H
#define OPENINGSCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class openingScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		openingScreen();
		~openingScreen();

	
	private:
		QPixmap *pixMap1;
		int x;
		int y;

};

#endif
