
#include "enemybullet.h"

#include <QList>
#include "player.h"
#include <QDebug>
#include <QTimer>
#include "game.h"
#include <qmath.h>



extern player* pl;



ebullet::ebullet(QString s):bullet(s)
{
    QTimer* time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(move()));

    time->start(25);



}

void ebullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

        // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
        for (int jjj = 0, n = colliding_items.size(); jjj < n; ++jjj){
            if (typeid(*(colliding_items[jjj])) == typeid(player)){


                pl->dechp(40);/////////////////////////////////



                scene()->removeItem(this);
                //free(this);
                delete this;



                return;
            }
        }







    if((pos().x()>scene()->sceneRect().width() )||(pos().y()>scene()->sceneRect().height()) ){
        scene()->removeItem(this);
       // free(this);
        delete this;
        qDebug()<<"DELETED";
        return;




    }

    int STEP_SIZE = 15;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


}

