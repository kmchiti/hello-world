#include "walking.h"
#include "player.h"
#include <QList>
#include "QTimer"
#include "bullet.h"
#include"pbullet.h"
#include <QPointF>
extern player* pl;





walking::walking(QPointF a,int spd, int lv, QString pix)
{
    speed=spd;
    setPos(a);
    health=(400+(lv*25));
    lvl=lv;
    armor=lvl;
    coldmg=lvl*10;
    speed=spd;
    setPixmap(QPixmap(pix));
    setTransformOriginPoint(72,78);
    //setRotation(90);
    QTimer *ti;
    ti=new QTimer(this);
    connect(ti,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    ti->start(25);

}

void walking::dechp(int i)
{
    health-=i;
    if(health<=0){

       // pl->EXPE(20+lvl);
       // pl->setmoney(lvl*10);
        scene()->removeItem(this);
        pl->scor++;
        //free(this);
        delete this;
        return;



    }
}

void walking::move()
{
   // QLineF ln(pos(),pl->pos());

    rotate(pl->pos(),72,78);
    double theta = rotation();



     if (collidesWithItem(pl)){

            // scene()->removeItem(this);
             //game->player->decrease(coldmg)


            double dy = 400 * qSin(qDegreesToRadians(theta));
            double dx =400 * qCos(qDegreesToRadians(theta));
            pl->dechp(coldmg);
            setPos(x()-dx, y()-dy);
            return;


        }
     else{
     QList<QGraphicsItem *> colliding_items = collidingItems();

         // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
         for (int i = 0, n = colliding_items.size(); i < n; ++i){
             if (typeid(*(colliding_items[i])) == typeid(pbullet)){
                 // increase the score

                 DEC(pl->returndmg());


                 // remove them from the scene (still on the heap)
                 scene()->removeItem(colliding_items[i]);


                 // delete them from the heap to save memory
                 delete colliding_items[i];
                 if(health<=0){
                          pl->EXPE(20+lvl);
                          pl->setmoney(30);
                          pl->scor++;
                          scene()->removeItem(this);
                         // free(this);
                          delete this;
                          return;


                      }


                 // return (all code below refers to a non existint bullet)
                 return;
             }
         }
     }
    /* if(health<=0){
         scene()->removeItem(this);
         delete this;


     }*/

        // move enemy forward at current angle

        double dy = speed * qSin(qDegreesToRadians(theta));
        double dx = speed * qCos(qDegreesToRadians(theta));

        setPos(x()+dx, y()+dy);

}
