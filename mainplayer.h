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


/**
	* This class is used to keep track of Main Player.
	* Inherits from QGraphicsPixmapItem.
	* @author Tam Henry Le Nguyen */

using namespace std;

class GraphicsWindow;

class MainPlayer : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		MainPlayer(); /** Constructor */
		MainPlayer(GraphicsWindow *p, QString name); /** Constructor */
		~MainPlayer(); /** Destructor */
		void setVelocity(double x, double y); /** Velocity Setter */
		void setVelocityY(double y); /** Velocity Setter*/
		void move(int x); /** Velocity Setter */
		void movejump(); /** Jump */
		void moveduck(); /** Duck */
		bool jumping; /** checks if jumping */
		bool ducking; /** checks if ducking */
		bool flinch; /** checks if flinching */
		void jumpCheck(); /** connector */
		QString getName(); /** returns name*/
		void flinching(); /** flinches */
		void setFloor(); /** Nothing */
		void resetFloor(); /** Nothing */
//		bool isAlive;
	
	private:
		GraphicsWindow *parent; /** parent */
		QGraphicsSimpleTextItem* nameID; /** name appears */
		QPixmap *pic; /** first pic */
		QPixmap *picduck; /** second pic */
		QPixmap *picflinch; /** third pic */
		QString name_; /** name */
		double velocityX; /** velocity X*/
		double velocityY; /** velocity Y*/
		double positionX; /** positionX */
		double positionY; /** position Y*/
		double accelX; /** accel X */
		double accelY; /** accel Y*/
		QTimer *timer; /** timer */
//		int counter;
		double floor; /** floor */

	public slots:
		void jump(); /** makes character jump */
};
#endif
