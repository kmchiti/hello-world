#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <qmath.h>
#include "QDebug"

void bullet::setdmg(int i)
{
    dmg=i;
}

bullet::bullet(QString s)
{
    setPixmap(QPixmap(s));
    setTransformOriginPoint(17,38);
    /*QTimer * timer = new QTimer(this);
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));

       // start the timer
       timer->start(25);*/
}

void bullet::rotate(QPointF p)
{
    const QPointF b(pos().x()+17,pos().y()+38);

    QLineF l(b,p);

    setRotation(-1 * l.angle());
}

int bullet::returndmg()
{
    return dmg;
}


