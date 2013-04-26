#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>

class Thing: public QGraphicsPixmapItem {

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
