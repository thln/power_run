#ifndef FATHER_H
#define FATHER_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class Father : public Thing {
	Q_OBJECT

	public:
		Father();
		Father(QPixmap *p, int nx, int ny);
		~Father();
//		void go();
		bool left;
		void move();	
	
	private:
		int x;
		int y;
		int vX;
		int vY;
		QPixmap *pixMap1;
		QPixmap *pixMap2;
//		QTimer *timer;

//	public slots:
//		void move();

};

#endif
