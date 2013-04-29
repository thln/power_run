#include "openingscreen.h"

using namespace std;

openingScreen::openingScreen()
{
	pixMap1 = new QPixmap("images/openingscreen.png");
	setPixmap(*pixMap1);
	x = 10;
	y = 10;
	setPos(x, y);

}

openingScreen::~openingScreen()
{

}
