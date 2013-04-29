#include "openingscreen.h"

using namespace std;

/** Constructor */
openingScreen::openingScreen()
{
	pixMap1 = new QPixmap("images/openingscreen.png");
	setPixmap(*pixMap1);
	x = 10;
	y = 10;
	setPos(x, y);

}

/** Destructor */
openingScreen::~openingScreen()
{

}
