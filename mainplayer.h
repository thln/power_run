#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include <string>
#include "graphicswindow.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <iostream>
#include <QTimer>
#include <QGraphicsSimpleTextItem>
#include <QFont>
#include <QBrush>


using namespace std;

class GraphicsWindow;

class MainPlayer : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		MainPlayer();
		MainPlayer(GraphicsWindow *p, QString name);
		~MainPlayer();
		void setVelocity(double x, double y);
		void setVelocityY(double y);
//		void KeyPressEvent(QKeyEvent *e);
		void move(int x, int y);
		void movejump();
		void moveduck();
		bool jumping;
		bool ducking;
		void jumpCheck();
		QString getName();
//		bool isAlive;
	
	private:
		GraphicsWindow *parent;
		QGraphicsSimpleTextItem* nameID;
		QPixmap *pic;
		QPixmap *picduck;
		QString name_;
		double velocityX;
		double velocityY;
//		QKeyevent *e;
		double positionX;
		double positionY;
		double accelX;
		double accelY;
		QTimer *timer;
//		int counter;
		double floor;

	public slots:
		void jump();
};
#endif
