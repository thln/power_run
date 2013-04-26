#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Thing: public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
//		Thing(QPixmap *p, int nx, int ny);
		virtual void move() = 0;
		
	private:
		int x;
		int y;
		int vX;
		int vY;
		QPixmap *pixMap;

};
/*
Thing::Thing(QPixmap *p, int nx, int ny)
{
	pixMap = p;
	x = nx;
	y = ny;
	setPos( x, y );
}
*/

#endif
