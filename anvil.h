#ifndef ANVIL_H
#define ANVIL_H

#include "thing.h"
#include <QObject>
#include <QTimer>
#include <iostream>

/**
	* This class is used to keep track of Anvil.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

using namespace std;

class Anvil : public Thing {
	Q_OBJECT

	public:
		Anvil(); /** Constructor */
		~Anvil(); /** Destructor */
		bool left; /** Nothing */
		void move(); /** Move */
		int getType();	/** Returns type  */
		int type; /** the type */
		bool isOpen; /** Nothing */	
		void faster(); /** Moves faster */
	
	private:
		int x; /** position X */
		int y; /** position Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap1; /** picture 1 */
		int counter; /** counter */

};

#endif
