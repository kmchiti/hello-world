#include"bullet_tower.h"
#include<QPixmap>
#include<QTimer>
#include<qmath.h>
#include<QGraphicsRectItem>
#include<QDebug>
#include<qmath.h>
#include<game.h>
#include<QGraphicsScene>
#include "shooter.h"
#include"walking.h"

extern Game* game;

Bullet::Bullet(QGraphicsItem *parent)
{
    //set graphics
    setPixmap(QPixmap(":/pics/bullet1.png"));;

    start=true;

    //connect timeer to move
    QTimer *move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
    move_timer->start(20);

    maxRange=500;
    distanceTraveld=0;
}



void Bullet::move()
{

    if((pos().x()>scene()->sceneRect().width() )||(pos().y()>scene()->sceneRect().height()) )
    {
        scene()->removeItem(this);
        //free(this);
        delete this;
        qDebug()<<"deleted";
        return;
     }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(shooter))
        {
              shooter *s=dynamic_cast<shooter *> ((colliding_items[i]));
              if(s)
              {
                s->dechp(100);//dameg!!!!!!!!!!!!!!!!!!!!!!!!!!!
              }
              scene()->removeItem(this);
              delete this;
              //free(this);
              //delete this;

              return;
           }
        if ( typeid(*(colliding_items[i])) == typeid(walking))
        {
            walking *s1=dynamic_cast<walking *> ((colliding_items[i]));
            if(s1)
            {
              s1->dechp(100);//dameg!!!!!!!!!!!!!!!!!!!!!!!!!!!
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    /*if(start){
        begian=pos();
        start=false;
    }
    QLineF ln(pos(),begian);
    //check bullet pos
    if(ln.length()>maxRange){
       qDebug()<<"max range\n";
       scene()->removeItem(this);
       delete this;
    }*/
    //qDebug()<<"rang="<<ln.length()<<"\n";
    int step_size=20;
    double theta=rotation();//degres
    double dy=step_size* qSin(qDegreesToRadians(theta));
    double dx=step_size* qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);
}

double Bullet::getMaxRenge()
{
    return maxRange;
}

double Bullet::getDistanceTraveld()
{
    return distanceTraveld;
}

void Bullet::setMaxRenge(double rng)
{
    maxRange=rng;
}

void Bullet::setDistanceTraveld(double dis)
{
    distanceTraveld=dis;
}

