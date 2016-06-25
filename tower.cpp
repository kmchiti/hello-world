#include"tower.h"
#include<QPixmap>
#include<QVector>
#include<QPointF>
#include<QPolygonF>
#include<QTimer>
#include"bullet_tower.h"
#include"game.h"
#include<QDebug>
#include "walking.h"
#include"shooter.h"
extern Game* game;

//list of point:(1,0)(2,0)(3,2)(3,2)(2,3)(1,3)(0,2)(0,1)

Tower::Tower(QGraphicsItem *parent, int id):QObject() , QGraphicsPixmapItem(parent)
{
    tower_id=id;

    //set the graphics
    setPixmap(QPixmap(":/pics/tower.png"));

    //creat point vevtor
    QVector<QPointF> points;
    points<<QPoint(1,0)<<QPoint(2,0)<<QPoint(3,1)<<QPoint(3,2)<<QPoint(2,3)<<QPoint(1,3)<<QPoint(0,2)<<QPoint(0,1);

    //scale points
    int scale_factor=130;
    for(size_t i=0,n=points.size();i<n;i++){
        points[i]*=scale_factor;
    }

    //creat polygon from this points
    QPolygonF polygon(points);

    //creat qgraphicspolygonItem
    attack_area = new QGraphicsPolygonItem(polygon,this);

    //hide that:
    //attack_area->hide();

    //move the polgon center to tower
    QPointF poly_center(1.5,1.5);
    poly_center*=scale_factor;
    poly_center=mapToScene(poly_center);
    QPointF tower_center(x()+70,y()+70);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());

    //set attack dest
    attack_dest=QPointF(0,0);

}

double Tower::distancTo(QGraphicsItem * item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

 void Tower::fire()
{
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+90,y()+90);
        QLineF ln(QPointF(x()+44,y()+44), attack_dest); //to attack to mouse pos--->QCursor::pos()
        int angle = -1*ln.angle();
        bullet->setRotation(angle);
        game->scene->addItem(bullet);
 }



void Tower::aquire_target()
{
    //get list of item colliding with attack_area
    QList<QGraphicsItem*>colliding_Items=attack_area->collidingItems();
    if (colliding_Items.size()==1)
    {
        has_target=false;
        return;
    }


    //find closest enemy
    double closest_dis=300;
    QPointF closest_pt=QPointF(0,0);
    for(size_t i=0,n=colliding_Items.size();i<n;i++)
    {
        //enemy* enem=dynamic_cast<enemy*>(colliding_Items[i]);
        walking* enem=dynamic_cast<walking*>(colliding_Items[i]);

        if(enem)
        {
             /*double this_dis=distancTo(enem);
             if(this_dis<closest_dis)
             {
                 closest_dis=this_dis;
                 closest_pt=colliding_Items[i]->pos();
                 has_target=true;
             }*/
            attack_dest=colliding_Items[i]->pos();
            qDebug()<<colliding_Items[i]->pos();
            fire();
            return;
        }
    }
    for(size_t i=0,n=colliding_Items.size();i<n;i++)
    {
        //enemy* enem=dynamic_cast<enemy*>(colliding_Items[i]);
        shooter* enem=dynamic_cast<shooter*>(colliding_Items[i]);

        if(enem)
        {
             /*double this_dis=distancTo(enem);
             if(this_dis<closest_dis)
             {
                 closest_dis=this_dis;
                 closest_pt=colliding_Items[i]->pos();
                 has_target=true;
             }*/

            attack_dest=colliding_Items[i]->pos();
            qDebug()<<colliding_Items[i]->pos();
            fire();
            return;
        }
    }
    /*if(has_target){
    attack_dest=closest_pt;
    fire();}
    //qDebug()<<"tower"<<tower_id<<"attack\n";*/


}

