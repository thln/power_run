#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
	* This class is used to keep track of pauseScreen.
	* Inherits from QObject and QGraphicsPixmapItem.
	* @author Tam Henry Le Nguyen */

class pauseScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		pauseScreen(); /** Constructor */
		~pauseScreen(); /** Destructor */

	
	private:
		QPixmap *pixMap1; /** Picture */
		int x; /** position X */
		int y; /** postion Y */

};

#endif
