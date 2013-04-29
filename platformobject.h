#ifndef PLATFORMOBJECT_H
#define PLATFORMOBJECT_H

#include "thing.h"
#include <QObject>
#include <QTimer>

class PlatformObject : public Thing {
	Q_OBJECT

	public:
		PlatformObject();
		PlatformObject(QPixmap *p, int nx, int ny);
		~PlatformObject();
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
//		QTimer *timer;

//	public slots:
//		void move();

};

#endif
