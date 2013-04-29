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
#include <QPixmap>
#include <QString>
#include <QImage>
#include "mainplayer.h"
#include "thing.h"
#include "mother.h"
#include "father.h"
#include "battery.h"
#include "door.h"
#include "dog.h"
#include "closingscreen.h"
#include "pausescreen.h"

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
	void setPlayer(QString name); /** Makes a player */
	MainPlayer *getPlayer(); /** Returns Player */
	void deletePlayer(); /** Checks to delete player */
  	void show(); /** shows the scene*/
    	void startgame(); /** Start game */
    	void pausegame(); /** Pause game */
	bool isAlive; /** checks if a player isAlive */
	QTimer *getTimer(); /** returns timer */
	double getScore(); /** returns score */
	int getLife(); /** returns number of lives */
	bool invincible; /** checks if in invincible mode */
	bool batteryOn; /** checks if just got battery */
    
private:
    QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view; /** What is being displayed */
    QTimer *timer; /** A Timer */ 
    
    MainPlayer *Player1; /** Main Player */
    vector<Thing*> MyThings; /** Vector of things */
    vector<QImage> MyBackground; /** to animate background */
    pauseScreen *pause; /** the pause button */

   	QPushButton *buttonclick; /** Nothing */
   	int counter; /** Nothing */
   	int index; /** a counter */
   	int imageindex;/** a counter */
   	double score;/** score */
   	int lives;/** lives */
   	int lastcase; /** no doubles */
   	int flinchcount;/** a counter */
   	int tempFloor;/** a counter */

public slots:
    void handleTimer(); /** Nothing */
	void clicker(); /** Nothing */
	void update(); /** Moves everything and does the actions */

};

#endif
