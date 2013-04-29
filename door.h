#ifndef DOOR_H
#define DOOR_H

#include "thing.h"
#include <QObject>
#include <QTimer>

/**
	* This class is used to keep track of Door.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

class Door : public Thing {
	Q_OBJECT

	public:
		Door(); /** Constructor */
		Door(QPixmap *p, int nx, int ny); /** Constructor */
		~Door(); /** Destructor */
		bool isOpen; /** checks if open */
		void move(); /** moves */
		int getType(); /** returns type */
		int type; /** the type */ 
	
	private:
		int x; /** position X */
		int y; /** position Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		int counter; /** counter */
		QPixmap *pixMap1; /** picture 1 */
		QPixmap *pixMap2; /** picture 2 */

};

#endif
