#ifndef BULLET_TOWER
#define BULLET_TOWER

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>

class Bullet :public QObject ,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);
public slots:
    void move();
    double getMaxRenge();
    double getDistanceTraveld();
    void setMaxRenge(double rng);
    void setDistanceTraveld(double dis);


private:

    double maxRange;
    double distanceTraveld;
    QPointF begian;
    bool start;

};

#endif // BULLET_TOWER

