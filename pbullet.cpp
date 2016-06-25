#include "pbullet.h"
#include<QGraphicsScene>
#include <qmath.h>
#include <QDebug>
#include <QTimer>
#include <QList>
#include "shooter.h"
#include"player.h"

extern player* pl;

pbullet::pbullet(QString s):bullet(s)
{
    QTimer*time=new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(move()));

    time->start(25);

}

void pbullet::move()
{if((pos().x()>scene()->sceneRect().width() )||(pos().y()>scene()->sceneRect().height()) ){
        scene()->removeItem(this);
        //free(this);
        delete this;
        qDebug()<<"deleted";
        return;




    }
    int STEP_SIZE = 30;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);





    QList<QGraphicsItem *> colliding_items = collidingItems();


        for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(shooter)){

              shooter *s=dynamic_cast<shooter *> ((colliding_items[i]));
              if(s){
              s->dechp(this->dmg);}
              scene()->removeItem(this);
              delete this;
              //free(this);
              //delete this;

              pl->scor++;

              return;
            }




}
}
