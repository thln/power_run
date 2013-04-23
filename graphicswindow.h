#ifndef GRAPHICSWINDOW_H
#define GRAPHICSWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QFormLayout>
#include <QLineEdit>
#include <QDockWidget>
#include <QLabel>
#include <QGraphicsRectItem>
#include <QMessageBox>

using namespace std;

/**
	* This class is used to keep track of all graphic tiles in the central widget.
	* Inherits from QGraphicsView.
	* @author Tam Henry Le Nguyen */

class GUITile;

class GraphicsWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    explicit GraphicsWindow(); /** Constructor */
    ~GraphicsWindow(); /** Destructor */
	QGraphicsScene *getScene(); /** Scene Accessor*/
  	void show(); /** shows the scene*/
    
private:
    QGraphicsScene *scene; /** What is being displayed */
    QGraphicsView *view; /** What is being displayed */
    QTimer *timer; /** A Timer */ 

   	QPushButton *buttonclick; /** Nothing */
   	int counter; /** Nothing */

public slots:
    void handleTimer(); /** Nothing */
	void clicker(); /** Nothing */

};

#endif