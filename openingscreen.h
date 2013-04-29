#ifndef OPENINGSCREEN_H
#define OPENINGSCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
	* This class is used to keep track of pauseScreen.
	* Inherits from QObject and QGraphicsPixmapItem.
	* @author Tam Henry Le Nguyen */

class openingScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		openingScreen(); /** Constructor */
		~openingScreen(); /** Destructor */

	
	private:
		QPixmap *pixMap1; /** picture */
		int x; /** position X */
		int y; /** position Y */

};

#endif
