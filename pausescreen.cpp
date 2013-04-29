#include "pausescreen.h"

using namespace std;

/** Constructor */
pauseScreen::pauseScreen()
{
	pixMap1 = new QPixmap("images/Pause.png");
	setPixmap(*pixMap1);
	x = 150;
	y = 100;
	setPos(x, y);

}

/** Destructor */
pauseScreen::~pauseScreen()
{

}
