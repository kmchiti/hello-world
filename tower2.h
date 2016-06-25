#ifndef TOWER2
#define TOWER2

#include<tower.h>
#include<QGraphicsSceneMouseEvent>

class Tower2:public Tower
{
    Q_OBJECT
public:
    Tower2(QGraphicsItem* parent=0);
    void fire();

public slots:
    void aquire_target();

private:
     QGraphicsTextItem* text2;
     bool f=true;
};

#endif // TOWER2

