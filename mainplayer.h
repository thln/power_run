#ifndef MAINPLAYER_H
#define MAINPLAYER_H
#include <String>

using namespace std;

class MainPlayer {
	Q_OBJECT

	public:
		MainPlayer();
		MainPlayer(GraphicsWindow *p, string name);
		~MainPlayer();
//		void KeyPressEvent(QKeyEvent *e);
//		void move();
	
	private:
		GraphicsWindow *parent;
		QPixMap *pic;
		string name_;
		double velocityX;
		double velocityY;
		QKeyevent *e;
//		double positionX;
//		double positionY;

	public slots:

};
#endif
