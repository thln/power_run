#include "mainplayer.h"

using namespace std;

MainPlayer::MainPlayer()
{

}


MainPlayer::MainPlayer(GraphicsWindow *p, string name)
{
	parent = p;
	name_ = name;

	pic = new QPixMap(":/images/mainplayerimage.png");
}

MainPlayer::~MainPlayer()
{

}
