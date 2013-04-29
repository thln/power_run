#ifndef CLOSINGSCREEN_H
#define CLOSINGSCREEN_H

#include <QObject>
#include <QGraphicsPixmapItem>

/**
	* This class is used to keep track of closingScreen.
	* Inherits from QObject and QGraphicsPixmapItem.
	* @author Tam Henry Le Nguyen */

class closingScreen : public QObject, public QGraphicsPixmapItem {
	Q_OBJECT

	public:
		closingScreen(); /** Constructor */
		~closingScreen(); /** Destructor */

	
	private:
		QPixmap *pixMap1; /** Picture */
		int x; /** position X */
		int y; /** position Y */

};

#endif
