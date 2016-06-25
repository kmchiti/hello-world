#ifndef TOWER
#define TOWER

#include<QGraphicsPixmapItem>
#include<QGraphicsPolygonItem>
#include<QGraphicsItem>
#include<QPointF>
#include<QObject>

class Tower : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(QGraphicsItem* parent=0,int id=0);
    double distancTo(QGraphicsItem* item);
    virtual void fire();

public slots:
    void aquire_target();

//private:
protected:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    bool has_target;
    int tower_id;


};


#endif // TOWER

