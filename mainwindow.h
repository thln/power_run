#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QToolBar>
#include <QAction>
#include <QDockWidget>
#include <QWidget>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QGraphicsRectItem>
#include "mainplayer.h"
#include <QToolBar>
#include <QAction>
#include <QWidget>
#include <QDockWidget>
#include "startscreenwindow.h"
#include <QInputDialog>
#include <QDir>
#include <QLabel>


using namespace std;

/**
	* This class is used to keep track of all widgets and graphicswindow.
	* Inherits from QMainWindow.
	* @author Tam Henry Le Nguyen */

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
	MainWindow(); /** Default Constructor */
	~MainWindow(); /** Default Destructor */
//	int getSize(); /** Size Accessor */
	
protected:
	void keyPressEvent(QKeyEvent *e); /** checks key used */
	
private:
	QToolBar *tool; /** A toolbar */
	startScreenWindow *startscreen; /** Starting screen */
	QString name; /** Name of player */
	QLineEdit *scoreOutput; /** outputs score */
	QLineEdit *lifeOutput; /** out puts number of lives */
	QLabel *label1;
	QLabel *label2;
	GraphicsWindow *gw; /** Your graphics Window */

public slots:
	void startGame(); /** slot for starting the game */
	void pauseGame(); /** slot for pausing game */
	void quitGame(); /** slot for quitting the game */
	bool clickedstate(); /** slot to check if it was clicked or not */
	void update(); /** updates score and lives */

};

#endif // MAINWINDOW_H
