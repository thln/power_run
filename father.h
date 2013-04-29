#ifndef FATHER_H
#define FATHER_H

#include "thing.h"
#include <QObject>
#include <QTimer>

/**
	* This class is used to keep track of Father.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

class Father : public Thing {
	Q_OBJECT

	public:
		Father(); /** Constructor */
		Father(QPixmap *p, int nx, int ny); /** Constructor */
		~Father(); /** Destructor */
		bool left; /** Nothing */
		void move(); /** Move */
		int getType(); /** Returns type */
		int type; /** number of type */
		bool isOpen; /** Nothing */		
	
	private:
		int x; /** position X*/
		int y; /** position Y*/
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap1; /** picture 1*/


};

#endif
