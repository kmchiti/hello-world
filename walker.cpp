/*
#include "walker.h"
#include <QPixmap>
#include <qmath.h>
#include <QTimer>





walker::walker(int spd, int lv, QString pix)
{
    health=(100+(lv*25));
    armor=lvl;
    coldmg=lvl*10;
    speed=spd;
    setPixmap(QPixmap(pix));
    setTransformOriginPoint(72,78);
    QTimer *time;
    time=new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(Move()));
    time->start(25);
}

void walker::Move()
{

    QLineF ln(pos(),ppo);

    rotate(ppo,72,78);
    double theta = rotation();



     if (ln.length() < 5){

            // scene()->removeItem(this);
             //game->player->decrease(coldmg)

            double dy = 8*speed * qSin(qDegreesToRadians(theta));
            double dx =8* speed * qCos(qDegreesToRadians(theta));
            setPos(x()-dx, y()-dy);
            return;


        }

        // move enemy forward at current angle

        double dy = speed * qSin(qDegreesToRadians(theta));
        double dx = speed * qCos(qDegreesToRadians(theta));

        setPos(x()+dx, y()+dy);
}*/
