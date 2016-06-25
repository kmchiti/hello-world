#ifndef GAME
#define GAME

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <player.h>
#include <QTimer>
#include "bullet.h"
#include "gun.h"
//#include "score.h"
#include "status.h"
#include "shooter.h"
#include "walking.h"
#include "enemybullet.h"
#include "pbullet.h"
#include"tower.h"

class Game: public QGraphicsView{
    Q_OBJECT

    int wave;
public:
    // member functions
    Game();

    void setCursor(QString filename);
    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    // member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem* cursor;
    Tower *build ;
    int count=0;

public slots:
    void spawnEnemy();
    void cursuring();
    //void rot(QMouseEvent *e);
};







#endif // GAME

