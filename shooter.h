#ifndef SHOOTER
#define SHOOTER


#include <QGraphicsItem>
#include <enemy.h>
#include "enemybullet.h"




// ////////////class shooter:public enemy{};
class shooter:public enemy{
    Q_OBJECT

public:
    shooter(QPointF a,int i);
    void dechp(int i);



public slots:
    void Shoot();
    void move();













};


#endif // SHOOTER

