#ifndef MOTHER_H
#define MOTHER_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class Mother : public Thing {
	Q_OBJECT

	public:
		Mother();
		Mother(QPixmap *p, int nx, int ny);
		~Mother();
//		void go();
//		bool left;
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
//		QTimer *timer;
		int counter;

//	public slots:
//		void move();

};

#endif
