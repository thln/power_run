#include "closingscreen.h"

using namespace std;

/** Constructor */
closingScreen::closingScreen()
{
	pixMap1 = new QPixmap("images/GameOver.png");
	setPixmap(*pixMap1);
	x = 150;
	y = 100;
	setPos(x, y);

}

/** Destructor */
closingScreen::~closingScreen()
{

}
