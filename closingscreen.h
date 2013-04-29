#ifndef CLOSINGSCREEN_H
#define CLOSINGSCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

class closingScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		closingScreen();
		~closingScreen();

	
	private:
		QPixmap *pixMap1;
		int x;
		int y;

};

#endif
