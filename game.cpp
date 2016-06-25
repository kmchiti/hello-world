#include <game.h>
#include <QBrush>
#include <QImage>

#include <QWidget>
#include <qmath.h>
#include "bullet.h"
#include "gun.h"
#include "walker.h"
#include <player.h>
#include"walking.h"
#include "shooting.h"
#include "shooter.h"
#include <QTimer>
#include<stdlib.h>
#include <qmath.h>
#include"tower1.h"
#include"tower2.h"
#include<QDebug>
#include <QMediaPlayer>


player *pl;
status *hth;
status *amo;
status *EXP;
status *LVL;
status *mny;
QTimer *TME;


//Score *scre;
//Score *hscre;

Game::Game(): QGraphicsView(){

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,2000,2000);
    setScene(scene);
    setMouseTracking(true);
    setFixedSize(1200,800);

    setBackgroundBrush(QBrush(QImage(":/pics/tilable-img_0044-lush.png")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    wave=1;

    pl=new player();
    pl->setFlag(QGraphicsItem::ItemIsFocusable);
    pl->setFocus();
    scene->setFocusItem(pl);

    pl->setPos(640,360);
    centerOn(pl->pos().x(),pl->pos().y());
    scene->addItem(pl);
    //scre= new Score(0,0);
   // hscre=new Score(0,1);
    //scene->addItem(scre);
    //scene->addItem(hscre);
    hth=new status(0,pl->returnhp());
    amo=new status(1,pl->returnammo());
    EXP=new status(2,pl->returnxp());
    LVL=new status(3,pl->returnlvl());
    mny= new status(4,pl->returnmoney());
    scene->addItem(hth);
    scene->addItem(amo);
    scene->addItem(EXP);
    scene->addItem(LVL);
    scene->addItem(mny);


    TME=new QTimer(this);
    connect(TME,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    TME->start(5000);

    QTimer *TME2=new QTimer(this);
    connect(TME2,SIGNAL(timeout()),this,SLOT(cursuring()));
    TME2->start(40);

    cursor =nullptr;
    build = nullptr;
    setMouseTracking(true);
}



void Game::mousePressEvent(QMouseEvent *event)
{
    QPointF a=mapToScene(event->pos());
    pl->rotate(a,68,41);
    //qreal aaaa=pl->rotation();
    QPointF z(pl->pos().x()+80,pl->pos().y()+40);
    //pl->ri->fire(z,aaaa);
    //pl->shot->fire(z,pl->rotation());
    //bullet *b=new bullet(":/pics/bullet2.png");
  //  b->rotate(a);
   // b->setRotation(pl->rotation());
    //QPointF z(17,38);
    pl->shoot();
   //QPointF zz=mapToParent(z);
   // b->setPos(pl->pos().x()+80,pl->pos().y()+40);
    //b->setPos((pl->pos().x()+(35*qCos(qDegreesToRadians(pl->rotation())))),(pl->pos().y()+(38*qSin(qDegreesToRadians(pl->rotation())))));
    //scene->addItem(b);

    if(build)
        {
            //return if cursor is collifing with tower
            QList<QGraphicsItem *>items=cursor->collidingItems();
            for(size_t i=0,n=items.size();i<n;i++){
                if(dynamic_cast<Tower *>(items[i]))
                    return;
            }
            scene->addItem(build);
            QPointF a=mapToScene(event->pos());
            build->setPos(a);
            cursor->hide();
            cursor = nullptr;
            build = nullptr;

        }
    else
        {
           // QGraphicsView::mousePressEvent(event);

        }


}

void Game::setCursor(QString filename)
{
    if(cursor)
    {
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor=new QGraphicsPixmapItem;
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);

}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor)
    {
        QPointF a=mapToScene(event->pos());
        cursor->setPos(a);
    }
}

/*void Game::keyPressEvent(QKeyEvent *event1)
{
    if(event1->key()==Qt::Key_T)
        {
            if(!build && count<3)
            {
                build=new Tower2();
                setCursor(QString(":/pics/turrets.png"));
                //count++;
            }
        }
        else if(event1->key()==Qt::Key_Y)
        {
            if(!build && count<3)
            {
                build=new Tower1();
                setCursor(QString(":/pics/turrets2.png"));
                //count++;
            }
        }
}*/

void Game::mouseDoubleClickEvent(QMouseEvent *event)
{
    QPointF a=mapToScene(event->pos());
    pl->rotate(a,68,41);

}

void Game::spawnEnemy()
{
    for(int I=0;I<wave;I++){
        int x;
        int y;
        x=rand()%3800;
       // x+=100;
        y=rand()%3800;
        //y+=100;

       // QLineF e(E,pl->pos());
        QLineF ee(x,y,pl->pos().x(),pl->pos().y());

        double theta=ee.angle();
        double dx=0;
        double dy=0;
        if(ee.length()>400){
            dy = 400 * qSin(qDegreesToRadians(theta));
            dx =400 * qCos(qDegreesToRadians(theta));


        }

        walking *w;
        w=new walking(QPointF(x-dx,y-dy),4,wave);
        w->setPos(w->pos().x()-dx,w->pos().y()-dy);
        scene->addItem(w);
        //walking* W;
        //W=new walking(QPointF(700,400),5);
        //scene->addItem(W);
        //W->setPos(x,y);

    }
    if(wave>3){
        for(int I=2;I<=wave;I++){
            int x;
            int y;
            x=rand()%3800;
           // x+=100;
            y=rand()%3800;
            //y+=100;

           // QLineF e(E,pl->pos());
            QLineF ee(x,y,pl->pos().x(),pl->pos().y());

            double theta=ee.angle();
            double dx=0;
            double dy=0;
            if(ee.length()>400){
                dy = 400 * qSin(qDegreesToRadians(theta));
                dx =400 * qCos(qDegreesToRadians(theta));

            }
            x-=dx;
            y-=dy;

            shooter *SS;
            SS=new shooter(QPointF(x,y),wave);
            scene->addItem(SS);


    }
  //  TME->setInterval(3000*wave);

   }
    wave++;
    TME->setInterval(3000*wave);
}

void Game::cursuring()
{
    QPointF a=mapToScene(QCursor::pos());
    //QLineF ln(pl->pos().x(),pl->pos().y(),QCursor::pos().x(),QCursor::pos().y());
    //int angle = -1*ln.angle();
  // pl->setTransformOriginPoint(55,55);
    //setrotation
    pl->rotate(a,68,41);
}
/*void Game::rot(QMouseEvent *e)
{
    pl->rotate(e->pos());

}
*/



