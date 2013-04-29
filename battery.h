#ifndef BATTERY_H
#define BATTERY_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class battery : public Thing {
	Q_OBJECT

	public:
		battery();
		battery(QPixmap *p, int nx, int ny);
		~battery();
//		void go();
		bool left;
		void move();
		int getType();	
		int type;
		bool isOpen;	
	
	private:
		int x;
		int y;
		int vX;
		int vY;
		QPixmap *pixMap1;
		QPixmap *pixMap2;
		int counter;
//		QTimer *timer;

//	public slots:
//		void move();

};

#endif
