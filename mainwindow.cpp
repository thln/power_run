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


	scoreOutput = new QLineEdit;
	scoreOutput->setReadOnly(true);
	tool->addWidget(scoreOutput);

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
//	delete startGameAction;
//	delete pauseGameAction;
//	delete QuitGameAction;
	delete tool;
//	delete startScreen;
	delete gw;

}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
//	int index;
	switch(e->key()) {
		case Qt::Key_Left :
			//Left Arrow Key pushed
			//if(!gw->getPlayer()->jumping)
			//{
				gw->getPlayer()->move(-8);
			 //}
			 break;
		case Qt::Key_Right :
			//Right Arrow Key pushed
			//if(!gw->getPlayer()->jumping)
			//{
				gw->getPlayer()->move(8);
			//}
			 break;
		case Qt::Key_Up : 
			//Up Arrow Key pushed
				if(!gw->getPlayer()->jumping)
				{
				gw->getPlayer()->setVelocityY(-16);
				gw->getPlayer()->movejump();
				}
				//gw->getPlayer()->jump();
			break;		
		case Qt::Key_Down : 
			//Down Arrow Key pushed
			gw->getPlayer()->moveduck();
			break;
	};
	
//	scoreOutput->setText(QString::number(gw->getScore()));
//	gw->getPlayer()->jumpCheck();
}

/** Slot to start game */
void MainWindow::startGame()
{

	delete startscreen;

//	bool ok;
//	QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("User name:"), QLineEdit::Normal, QDir::home().dirName(), &ok);


	gw = new GraphicsWindow;
	gw->setBackgroundBrush(QImage("images/testbackground.png"));
	gw->setCacheMode(QGraphicsView::CacheBackground);
	setCentralWidget(gw);
	
	  connect(gw->getTimer(), SIGNAL(timeout()), this, SLOT(update()));



//	cout << "Error?" << endl;

//	if(gw->getPlayer() != NULL)
//	{
		gw->deletePlayer();
//	}


//	cout << "Error?" << endl;

	this->setFocus();

//	string name = "Henry";
	gw->setPlayer(name);
	gw->startgame();

//	while(gw->getTimer()->isActive())
//	{	
//	scoreOutput->setText(QString::number(gw->getScore()));
//	}
/*
//Takes inputs from lineedits and store them in respective values
	size = textfields->getSizeEdit()->text().toInt();
	randMoves = textfields->getStartMovesEdit()->text().toInt();
	randSeed = textfields->getRandomSeedEdit()->text().toInt();
	
//Printing out error messages if any
	tempOutput->appendPlainText("Size: "+ QString::number(size));
	tempOutput->appendPlainText("# of random Moves: "+ QString::number(randMoves));	
	tempOutput->appendPlainText("random Seed Number: "+ QString::number(randSeed));

	if(randMoves <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Start Move value greater than 0.");
	}
	else if(randSeed <= 0)
	{
		tempOutput->appendPlainText("Error: Needs a Random Seed value greater than 0.");
	}
	else if(size != 9 && size != 16)
	{
		tempOutput->appendPlainText("Error: Size can only be of 3x3(9) or 4x4(16).");
	}
	else
	{
		tempOutput->appendPlainText("Game will now begin!");
		gw->setBoard(new Board(size, randMoves, randSeed));
		int dim = sqrt(size);
		QPen blackPen(Qt::black);
  		QBrush blueBrush(Qt::blue);
  		QBrush whiteBrush(Qt::white);
  		QBrush yellowBrush(Qt::yellow);
  		int index = 0;
  			srand(randSeed);
 
//making the tiles 		
		for(int i=0; i<dim; i++)
		{
			for(int j=0; j<dim; j++)
			{ 
			gw->setTilesAt(index, new GUITile(gw, gw->getBoard()->getTiles()[index], (j*(100)), (i*(100)), 100, 100));
			
			if(gw->getBoard()->getTiles()[index] != 0)
			{
				gw->getTilesAt(index)->setBrush(blueBrush);
				gw->getTilesAt(index)->setPen(blackPen);
			}
			else
			{
				gw->getTilesAt(index)->setBrush(whiteBrush);
				gw->getTilesAt(index)->setPen(blackPen);			
			}
			gw->getScene()->addItem(gw->getTiles()[index]);
			index++;
			}
		}

	}
*/
}

/** Slot to start cheating on game */
void MainWindow::pauseGame()
{

	gw->pausegame();
/*
	if(mhChoice->isChecked())
	{
		tempOutput->appendPlainText("Manhattan Cheat!");
		ManhattanHeuristic *MH = new ManhattanHeuristic;
		PuzzleSolver* Answer = new PuzzleSolver(*(gw->getBoard()));
		Answer->run(MH);
		tempOutput->appendPlainText("Try this: ");
		for(int i=( Answer->getSolutions().getSize()-1 ); i>=0; i--)
		{
		tempOutput->appendPlainText(QString::number(Answer->getSolutions()[i]));
		}
	}
	else if(ooohChoice->isChecked())
	{
		tempOutput->appendPlainText("Out of Order Cheat!");
		OutOfPlaceHeuristic *OOPH = new OutOfPlaceHeuristic;
		PuzzleSolver* Answer = new PuzzleSolver(*(gw->getBoard()));
		Answer->run(OOPH);
		tempOutput->appendPlainText("Try this: ");
		for(int i=( Answer->getSolutions().getSize()-1 ); i>=0; i--)
		{
		tempOutput->appendPlainText(QString::number(Answer->getSolutions()[i]));
		}
	}
	else if(size != 9 && size != 16)
	{
		tempOutput->appendPlainText("Please start the game first.");
	}
	else
	{
		tempOutput->appendPlainText("Please choose a cheat first.");
	}

*/
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
