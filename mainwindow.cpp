#include "mainwindow.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QToolBar>
#include <QAction>
#include <QDockWidget>
#include <QWidget>
#include <QString>
#include <math.h>
//#include "board.h"

using namespace std;

/** Default Constructor */
MainWindow::MainWindow()
{

	startscreen = new startScreenWindow;
	setCentralWidget(startscreen);
//	gw = new GraphicsWindow;
//	gw->setBackgroundBrush(QImage("images/testbackground.png"));
//	gw->setCacheMode(QGraphicsView::CacheBackground);
//	setCentralWidget(gw);
	//setFocus();

	//string name = "Henry";
	//gw->setPlayer(name);


//---------------------------------------------------------------
//Toolbar
	tool = new QToolBar;

//Actions
	QAction *startGameAction = new QAction(tr("&Start Game"), this);
	tool->addAction( startGameAction );
	connect( startGameAction, SIGNAL(triggered() ), this, SLOT(startGame() ));

	QAction *pauseGameAction = new QAction(tr("&Pause Game"), this);
	tool->addAction( pauseGameAction );
	connect( pauseGameAction, SIGNAL(triggered() ), this, SLOT( pauseGame() ));

	QAction *quitGameAction = new QAction(tr("&Quit Game"), this);
	tool->addAction( quitGameAction );
	connect( quitGameAction, SIGNAL(triggered() ), this, SLOT(quitGame() ));

	label1 = new QLabel;
	label1->setText("score");
	tool->addWidget(label1);

	scoreOutput = new QLineEdit;
	scoreOutput->setReadOnly(true);
	tool->addWidget(scoreOutput);

	label2 = new QLabel;
	label2->setText("score");
	tool->addWidget(label2);

	lifeOutput = new QLineEdit;
	lifeOutput->setReadOnly(true);
	tool->addWidget(lifeOutput);

//	tool->show();
	
	bool ok;
	name = QInputDialog::getText(this, tr("Name?"), tr("Don't forget to resize the window!"), QLineEdit::Normal, QDir::home().dirName(), &ok);

	QDockWidget *tqdw = new QDockWidget();
	tqdw->setWidget(tool);
	addDockWidget(Qt::TopDockWidgetArea, tqdw);
	tqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

/*
//---------------------------------------------------------------
//Radio Buttons between Heuristics
	mhChoice = new QRadioButton(tr("&Manhattan Heuristic"), this);
	connect(mhChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	ooohChoice = new QRadioButton(tr("&Out Of Order Heuristic"), this);
	connect( ooohChoice, SIGNAL(clicked(bool)), this, SLOT(clickedstate()));

	mhChoice->setChecked(false);
	ooohChoice->setChecked(false);

	tool->addWidget(mhChoice);
	tool->addWidget(ooohChoice);

	tool->show();

	QDockWidget *tqdw = new QDockWidget();
	tqdw->setWidget(tool);
	addDockWidget(Qt::TopDockWidgetArea, tqdw);
	tqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);


//---------------------------------------------------------------
//Text Boxes to store values for starting game

	textfields = new formlayout();

	lqdw = new QDockWidget();
	lqdw->setWidget(textfields);
	addDockWidget(Qt::LeftDockWidgetArea, lqdw);
	lqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//---------------------------------------------------------------
//Temporary Messages to text outputs

	tempOutput = new QPlainTextEdit();
	tempOutput->setReadOnly(true);

	QDockWidget *rqdw = new QDockWidget();
	rqdw->setWidget(tempOutput);
	addDockWidget(Qt::RightDockWidgetArea, rqdw);
	rqdw->setFeatures(QDockWidget::NoDockWidgetFeatures);

//--------------------------------------------------------------
*/

}

/** Default Destructor */
MainWindow::~MainWindow()
{
	delete tool;
	delete gw;

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

	switch(e->key()) {
		case Qt::Key_Left :
			//Left Arrow Key pushed
				gw->getPlayer()->move(-8);
			 break;
		case Qt::Key_Right :
			//Right Arrow Key pushed			
				gw->getPlayer()->move(8);
			 break;
		case Qt::Key_Up : 
			//Up Arrow Key pushed
				if(!gw->getPlayer()->jumping)
				{;
				gw->getPlayer()->setVelocityY(-16);
				gw->getPlayer()->movejump();
				}
			break;		
		case Qt::Key_Down : 
			//Down Arrow Key pushed
			gw->getPlayer()->moveduck();
			break;
	};
	
}

/** Slot to start game */
void MainWindow::startGame()
{

	delete startscreen;


	gw = new GraphicsWindow;
	gw->setBackgroundBrush(QImage("images/testbackground.png"));
	gw->setCacheMode(QGraphicsView::CacheBackground);
	setCentralWidget(gw);
	
	  connect(gw->getTimer(), SIGNAL(timeout()), this, SLOT(update()));

		gw->deletePlayer();

	this->setFocus();

	gw->setPlayer(name);
	gw->startgame();


}

/** Slot to start cheating on game */
void MainWindow::pauseGame()
{

	gw->pausegame();
}

/** Slot to quit game */
void MainWindow::quitGame()
{
	exit(EXIT_FAILURE);
}

/** Slot to check if clicked */
bool MainWindow::clickedstate()
{
	return false;
}

void MainWindow::update()
{
	scoreOutput->setText(QString::number(gw->getScore()));
	lifeOutput->setText(QString::number(gw->getLife()));
	
//	if(gw->getLife() == 0)
//	{
	//gameover
//	}
}
