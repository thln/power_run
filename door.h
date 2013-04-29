#ifndef DOOR_H
#define DOOR_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class Door : public Thing {
	Q_OBJECT

	public:
		Door();
		Door(QPixmap *p, int nx, int ny);
		~Door();
//		void go();
		bool isOpen;
		void move();
		int getType();
		int type;	
	
	private:
		int x;
		int y;
		int vX;
		int vY;
		int counter;
		QPixmap *pixMap1;
		QPixmap *pixMap2;
//		QTimer *timer;

//	public slots:


};

#endif
