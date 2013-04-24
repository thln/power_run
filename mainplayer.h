#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include <string>
#include "graphicswindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>

using namespace std;

class GraphicsWindow;

class MainPlayer : public QGraphicsPixmapItem {
//	Q_OBJECT

	public:
		MainPlayer();
		MainPlayer(GraphicsWindow *p, string name);
		~MainPlayer();
		void setVelocity(double x, double y);
//		void KeyPressEvent(QKeyEvent *e);
		void move(int x, int y);
	
	private:
		GraphicsWindow *parent;
		QPixmap *pic;
		string name_;
		double velocityX;
		double velocityY;
//		QKeyevent *e;
		double positionX;
		double positionY;

	public slots:

};
#endif
