#include"tower2.h"
#include<QTimer>
#include"bullet_tower.h"
#include"game.h"
#include<QDebug>
#include<qmath.h>

extern Game* game;

Tower2::Tower2(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/pics/turrets.png"));

    QPointF poly_center(1.5,1.5);
    poly_center*=130;
    poly_center=mapToScene(poly_center);
    QPointF tower_center(x()+50,y()+50);
    QLineF ln(poly_center,tower_center);
    Tower::attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //connect timer to aquire_target
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);
}

void Tower2::fire()
{
    Bullet* bullet = new Bullet();
    bullet->setPos(x()+90,y()+90);
    QLineF ln(QPointF(x()+44,y()+44), attack_dest); //to attack to mouse pos--->QCursor::pos()
    int angle = -1*ln.angle();
    bullet->setRotation(angle);
    setTransformOriginPoint(55,55);
    //setrotation
    setRotation(angle);
    game->scene->addItem(bullet);


    Bullet* bullet2 = new Bullet();
    bullet2->setPos(x()+90,y()+90);
    QLineF ln2(QPointF(x()+44,y()+44), attack_dest);
    int angle2= -1*ln2.angle();
    bullet2->setRotation(angle2);
    game->scene->addItem(bullet2);

}


void Tower2::aquire_target()
{
    Tower::aquire_target();
}

