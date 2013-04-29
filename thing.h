#ifndef THING_H
#define THING_H
#include <QGraphicsPixmapItem>
#include <QObject>

/**
	* This Abstract class is used to keep track of all things.
	* Inherits from QObject and QGraphicsPixmapItem.
	* @author Tam Henry Le Nguyen */

class Thing: public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		virtual void move() = 0; /** Move */
		virtual int getType() = 0; /** Returns Type */
		int type; /** The Type */
		bool isOpen; /** Nothing */
		
	private:
		int x; /** position X */
		int y; /** positon Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap; /** picture */

};

#endif
