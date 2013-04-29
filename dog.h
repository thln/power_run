#ifndef DOG_H
#define DOG_H

#include "thing.h"
#include <QObject>
#include <QTimer>

/**
	* This class is used to keep track of Dog.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

class Dog : public Thing {
	Q_OBJECT

	public:
		Dog(); /** Constructor */
		Dog(QPixmap *p, int nx, int ny); /** Constructor */
		~Dog(); /** Destructor */
		bool left; /** Nothing */
		void move(); /** Move */
		int getType();	/** Returns type  */
		int type; /** the type */
		bool isOpen; /** Nothing */	
	
	private:
		int x; /** position X */
		int y; /** position Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap1; /** picture 1 */
		int counter; /** counter */

};

#endif
