#include "shooter.h"
#include <QGraphicsScene>
#include "player.h"
#include "game.h"
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>


extern player *pl;


shooter::shooter(QPointF a, int i)
{
    setPixmap(QPixmap(":/pics/shooting.png"));
    health=(200+(i*25));
    lvl=i;
    armor=lvl;
    coldmg=lvl*10;
    setPos(a);
    QTimer *T;
    T=new QTimer(this);
    connect(T,SIGNAL(timeout()),this,SLOT(Shoot()));
    setTransformOriginPoint(63,54);
    T->start(5000);


    QTimer *TTT;
    TTT= new QTimer(this);
    connect(TTT,SIGNAL(timeout()),this,SLOT(move()));
    TTT->start(30);





}


void shooter::dechp(int i)
{
    health-=i;
    if(health<=0){

        pl->EXPE(25+lvl);
        pl->setmoney(10);
        pl->scor++;
        scene()->removeItem(this);
        //free(this);
        delete this;
        return;



    }
}

void shooter::Shoot()
{
    ebullet *b;
    b=new ebullet(":/pics/bullet1.png");
    b->setdmg(coldmg);
    scene()->addItem(b);
    //QPointF A=(pl->pos().x()+63,pl->pos().y()+40);
   // QPointF *A;
    QPointF a(pl->pos().x()+63,pl->pos().y()+40);
    //A=new QPointF(pl->pos().x()+63,pl->pos().y()+40);
    //QPointF AA=A;
    rotate(a,63,54);
     b->setPos(this->pos().x()+60,this->pos().y()+40);
    b->setRotation(this->rotation());
   // b->rotate(pl->pos());
   // b->setPos(this->pos().x()+60,this->pos().y()+40);

  //  b->setRotation(this->rotation());

}

void shooter::move()
{
       // QLineF ln(pos(),pl->pos());

        rotate(pl->pos(),63,54);
        double theta = rotation();



         if (collidesWithItem(pl)){




                double dy = 400 * qSin(qDegreesToRadians(theta));
                double dx =400 * qCos(qDegreesToRadians(theta));

                setPos(x()-dx, y()-dy);
                return;


            }
         QLineF a(this->pos().x(),this->pos().y(),pl->pos().x(),pl->pos().y());
         if(a.length()>400){
             double dy = 6 * qSin(qDegreesToRadians(theta));
             double dx = 6 * qCos(qDegreesToRadians(theta));

             setPos(x()+dx, y()+dy);
             return;




         }





    }



