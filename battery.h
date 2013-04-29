#ifndef BATTERY_H
#define BATTERY_H

#include "thing.h"
#include <QObject>
#include <QTimer>

/**
	* This class is used to keep track of Battery.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

class battery : public Thing {
	Q_OBJECT

	public:
		battery(); /** Constructor */
		~battery(); /** Destructor */
		bool left; /** Nothing */
		void move(); /** Move */
		int getType();	 /** Returns type */
		int type; /** the type */
		bool isOpen; /** Nothing */	
	
	private:
		int x; /** position X */
		int y; /** position Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap1; /** picture  */
		int counter; /** counter */

};

#endif
