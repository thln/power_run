#ifndef MOTHER_H
#define MOTHER_H

#include "thing.h"
#include <QObject>
#include <QTimer>

/**
	* This class is used to keep track of Mother.
	* Inherits from Thing.
	* @author Tam Henry Le Nguyen */

class Mother : public Thing {
	Q_OBJECT

	public:
		Mother(); /** Constructor */
		Mother(QPixmap *p, int nx, int ny); /** Constructor */
		~Mother(); /** Destructor */
		void move(); /** Move */
		int getType(); /** returns type */ 
		int type; /** the Type */
		bool isOpen; /** Nothing */	
	
	private:
		int x; /** position X */
		int y; /** position Y */
		int vX; /** velocity X */
		int vY; /** velocity Y */
		QPixmap *pixMap1; /** picture 1 */
		QPixmap *pixMap2; /** picture 2 */
		int counter; /** counter */

};

#endif
