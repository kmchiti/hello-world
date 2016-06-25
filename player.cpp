#include "player.h"
#include <QPixmap>
#include "gun.h"
#include "bullet.h"
#include "status.h"
#include"pbullet.h"
#include"tower1.h"
#include"tower2.h"
#include"tower3.h"
#include<QDebug>
#include<QGraphicsView>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <qmediaplayer.h>

extern Game* game;
extern status *hth;
//extern QPointF ppo;
extern status *amo;
extern status *EXP;
extern status *LVL;
extern status *mny;
extern QGraphicsScene* scene_over;
extern QTimer *TME;
extern QGraphicsView* view;
extern QGraphicsTextItem* text2;

void player::shoot()
{
   // bullet *b=new bullet(":/pics/bullet2.png");
    //b->rotate(a);
    //b->setRotation(this->rotation());
   // b->setPos(this->pos().x()+80,this->pos().y()+40);
   // game->scene->addItem(b);
    if(gtype==1){
    rifle->fire();
    if(RI->state()==QMediaPlayer::PlayingState){
        RI->setPosition(0);
    }
    else if(RI->state()==QMediaPlayer::StoppedState)
        RI->play();




    }
    else{
        if(AMMO>0){

            shot->fire();
            if(SHO->state()==QMediaPlayer::PlayingState){
                SHO->setPosition(0);
            }
            else if(SHO->state()==QMediaPlayer::StoppedState)
                SHO->play();





            AMMO--;
            amo->set(AMMO);
        }


        }
    }



player::player(int lv, int mny,int ar, int ex, QString pix)
{
    lvl=lv;
    maxhp=(100+(lv*55));
    health=maxhp;
    armor=ar;
    money=mny;
    scor=0;
    experience=ex;
    AMMO=10;
    setPixmap(QPixmap(pix));
    gtype=1;
    setTransformOriginPoint(63,40);
    QString Ri(":/pics/bullet2.png");
    rifle=new gun((int)100,(int)1,Ri);
    shot=new gun((int)70,(int)3,":/pics/bullet1.png");
    RI=new QMediaPlayer(this);
    SHO=new QMediaPlayer(this);
    RI->setMedia(QUrl("qrc:/music/Futuristic SMG Single Shot.wav"));
    SHO->setMedia(QUrl("qrc:/music/10 Guage Shotgun-SoundBible.com-74120584.wav"));




}

void player::keyPressEvent(QKeyEvent *event)
{

    double theta = rotation();
    double dy = 50 * qSin(qDegreesToRadians(theta));
    double dx =50 * qCos(qDegreesToRadians(theta));



    if (event->key() == Qt::Key_A){
          if (pos().x() > 10){
          setPos(x()-7,y());
          game->centerOn(pos().x(),pos().y());
          hth->setPos(hth->pos().x()-7,hth->pos().y());
          amo->setPos(amo->pos().x()-7,amo->pos().y());
          EXP->setPos(EXP->pos().x()-7,EXP->pos().y());
          LVL->setPos(LVL->pos().x()-7,LVL->pos().y());
          mny->setPos(mny->pos().x()-7,mny->pos().y());
          }

      }
      else if (event->key() == Qt::Key_D){
          if (pos().x() + 100 < scene()->sceneRect().width()){
          setPos(x()+7,y());
          game->centerOn(pos().x(),pos().y());
          hth->setPos(hth->pos().x()+7,hth->pos().y());
          amo->setPos(amo->pos().x()+7,amo->pos().y());
          EXP->setPos(EXP->pos().x()+7,EXP->pos().y());
          LVL->setPos(LVL->pos().x()+7,LVL->pos().y());
           mny->setPos(mny->pos().x()+7,mny->pos().y());
          }
      }


      else if (event->key() == Qt::Key_W){

        if(pos().y()>10){
            setPos(x(),y()-7);
            game->centerOn(pos().x(),pos().y());
            hth->setPos(hth->pos().x(),hth->pos().y()-7);
            amo->setPos(amo->pos().x(),amo->pos().y()-7);
            EXP->setPos(EXP->pos().x(),EXP->pos().y()-7);
            LVL->setPos(LVL->pos().x(),LVL->pos().y()-7);
             mny->setPos(mny->pos().x(),mny->pos().y()-7);
            }


      }
      else if (event->key() == Qt::Key_S){

        if(pos().y()<scene()->sceneRect().height()-100){
            setPos(x(),y()+7);
            game->centerOn(pos().x(),pos().y());
            hth->setPos(hth->pos().x(),hth->pos().y()+7);
            amo->setPos(amo->pos().x(),amo->pos().y()+7);
            EXP->setPos(EXP->pos().x(),EXP->pos().y()+7);
            LVL->setPos(LVL->pos().x(),LVL->pos().y()+7);
             mny->setPos(mny->pos().x(),mny->pos().y()+7);
            }

      }
    else if (event->key() == Qt::Key_Q){

        if(gtype==1){
            gtype*=-1;
            setPixmap(QPixmap(":/pics/shotgun.png"));
        }
        else{
            gtype*=-1;
            setPixmap(QPixmap(":/pics/rifle.png"));
        }
    }
    else if (event->key() == Qt::Key_Escape){
        exit(0);
    }
    else if (event->key() == Qt::Key_Space){

        if((pos().x()>0)&&(pos().x()<scene()->sceneRect().width()-100)){
            if((pos().y()>0)&&(pos().y()<scene()->sceneRect().height()-80)){
                 setPos(x()-dx, y()-dy);
                 game->centerOn(pos().x(),pos().y());
                 hth->setPos(hth->pos().x()-dx,hth->pos().y()-dy);
                 amo->setPos(amo->pos().x()-dx,amo->pos().y()-dy);
                 EXP->setPos(EXP->pos().x()-dx,EXP->pos().y()-dy);
                 LVL->setPos(LVL->pos().x()-dx,LVL->pos().y()-dy);
                 mny->setPos(mny->pos().x()-dx,mny->pos().y()-dy);
            }
        }

    }
    else if (event->key() == Qt::Key_E){
        if(money>=100){
            shot->upgr();
            money-=100;
            mny->set(money);

        }
    }
    else if (event->key() == Qt::Key_F){
        if(money>=10){
            AMMO+=5;
            amo->set(AMMO);
            money-=10;
            mny->set(money);

        }
    }

    //ppo=pos();


      else if(event->key()==Qt::Key_T)
        {
            if(!game->build && game->count<3)
            {
                if(money>=50){game->build=new Tower2();
                game->setCursor(QString(":/pics/turrets.png"));

                setmoney(-50);

                }
                //count++;
            }
        }
        else if(event->key()==Qt::Key_Y)
        {
            if(!game->build && game->count<3)
            {
                if(money>=50){
                    game->build=new Tower1();
                    game->setCursor(QString(":/pics/turrets2.png"));

                    setmoney(-50);
                 }

            }
        }
        else if (event->key() == Qt::Key_U){
        if(!game->build && game->count<3)
        {
            if(money>=150){
                game->build=new Tower3();
                game->setCursor(QString(":/pics/turrets3F.png"));

                setmoney(-150);
            }
        }
        }

}

int player::returnhp()
{return health;

}

int player::returnammo()
{
        return AMMO;


}

int player::returnxp()
{return experience;

}

int player::returnlvl()
{
    return lvl;
}

void player::dechp(int i)
{

    health-=(int)((double)(i*(500-armor)/500));
    hth->set(health);
    if(health<=0)
    {
      end=true;
      //exit(0);

      QFile FILE("s.txt");
            FILE.open(QIODevice::ReadOnly|QIODevice::Text);
            int III=0;
            QTextStream in(&FILE);
            in>>III;
            FILE.close();
            if(scor>III){




                QFile File("s.txt");
                File.open(QIODevice::WriteOnly|QIODevice::Text);

                QTextStream in(&File);
                in<<scor;
                File.close();



            };

      text2->setPlainText(QString("GAME OVER") +QString("\n score:") + QString::number(scor)) ;

      view->setScene(scene_over);
      game->hide();

       qDebug()<<"game over\n";

       TME->stop();
    }
}
int player::returndmg()
{
    if(gtype==1){
    return rifle->returnDMG();
    }
    else{

        return shot->returnDMG();


    }
}

void player::EXPE(int i)
{
    experience+=i;
    while(experience>=100){
        experience-=100;
        lvl++;
        AMMO+=5;
        armor+=15;
        maxhp+=55;
        health=maxhp;
        hth->set(health);
        amo->set(AMMO);
        LVL->set(lvl);
        upgrd(1);
    }
    EXP->set(experience);
}

void player::setmoney(int i)
{
    money+=i;
    mny->set(money);
}

int player::returnmoney()
{
    return money;
}

void player::upgrd(int i)
{
    if(i==1)
        rifle->upgr();
    else
        shot->upgr();
}




