#ifndef MOTHER_H
#define MOTHER_H

#include "thing.h"

class Mother : public Thing {

	public:
		Mother();
		Mother(QPixmap *p, int nx, int ny);
		~Mother();
		void move();
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

};

#endif
