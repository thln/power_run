#ifndef DOG_H
#define DOG_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class Dog : public Thing {
	Q_OBJECT

	public:
		Dog();
		Dog(QPixmap *p, int nx, int ny);
		~Dog();
		void go();
		bool left;
	
	
	private:
		int x;
		int y;
		int vX;
		int vY;
		QPixmap *pixMap1;
		QPixmap *pixMap2;
		QTimer *timer;

	public slots:
		void move();

};

#endif
