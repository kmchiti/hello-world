#include"tower3.h"
#include<QTimer>
#include"bullet_tower.h"
#include"game.h"
#include"walking.h"
#include"shooter.h"

extern Game* game;

Tower3::Tower3(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/pics/turrets3.png"));

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

void Tower3::fire()
{
    Bullet* bullet = new Bullet();
    bullet->setPos(x()+90,y()+90);
    QLineF ln(QPointF(x()+44,y()+44), attack_dest); //to attack to mouse pos--->QCursor::pos()
    int angle = -1*ln.angle();


    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower3::aquire_target()
{
    //get list of item colliding with attack_area
    QList<QGraphicsItem*>colliding_Items=attack_area->collidingItems();
    if (colliding_Items.size()==1)
    {
        has_target=false;
        return;
    }
    for(size_t i=0,n=colliding_Items.size();i<n;i++)
    {
        walking* Enem=dynamic_cast<walking*>(colliding_Items[i]);

        if(Enem)
        {
            attack_dest=colliding_Items[i]->pos();
            has_target=true;
            fire();
        }
    }
    for(size_t i=0,n=colliding_Items.size();i<n;i++)
    {
        shooter* enem=dynamic_cast<shooter*>(colliding_Items[i]);

        if(enem)
        {
            attack_dest=colliding_Items[i]->pos();
            has_target=true;
            fire();
        }
    }

//    fire();
}

