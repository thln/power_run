#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <time.h>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QFormLayout>
#include <QLineEdit>
#include <QDockWidget>
#include <QLabel>
#include <QGraphicsRectItem>
#include <QMessageBox>
//#include <stdio.h>
//#include <stdlib.h>
#include "mainplayer.h"
#include "thing.h"
#include "mother.h"
#include "father.h"
#include "platformobject.h"
#include "door.h"
#include "dog.h"

using namespace std;

/**
	* This class is used to keep track of all graphic tiles in the central widget.
	* Inherits from QGraphicsView.
	* @author Tam Henry Le Nguyen */

class MainPlayer;

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicsWindow(); /** Constructor */
    ~GraphicsWindow(); /** Destructor */
	QGraphicsScene *getScene(); /** Scene Accessor*/
	void setPlayer(string name);
	MainPlayer *getPlayer();
	void deletePlayer();
  	void show(); /** shows the scene*/
    	void startgame();
    	void pausegame();
	bool isAlive;
    
private:
    QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view; /** What is being displayed */
    QTimer *timer; /** A Timer */ 
    
    MainPlayer *Player1;
 //   	Mother *test;
    vector<Thing*> MyThings;

   	QPushButton *buttonclick; /** Nothing */
   	int counter; /** Nothing */
   	int index;
  // 	int counter;

public slots:
    void handleTimer(); /** Nothing */
	void clicker(); /** Nothing */
	void update();

};

#endif
