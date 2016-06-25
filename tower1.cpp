#include"tower1.h"
#include<QTimer>
#include"bullet_tower.h"
#include"game.h"

extern Game* game;

Tower1::Tower1(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/pics/turrets2.png"));

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

void Tower1::fire()
{
    Bullet* bullet = new Bullet();
    bullet->setPos(x()+90,y()+90);
    QLineF ln(QPointF(x()+44,y()+44), attack_dest);
    int angle = -1*ln.angle();

    setTransformOriginPoint(55,55);
    //setrotation
    setRotation(angle);

    bullet->setRotation(angle);
    game->scene->addItem(bullet);

}

void Tower1::aquire_target()
{
    Tower::aquire_target();
}

