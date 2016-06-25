#ifndef TOWER3
#define TOWER3


#include<tower.h>
#include<QGraphicsSceneMouseEvent>

class Tower3:public Tower
{
    Q_OBJECT
public:
    Tower3(QGraphicsItem* parent=0);
    void fire();

public slots:
    void aquire_target();

private:
     QGraphicsTextItem* text2;
     bool f=true;
};

#endif // TOWER3

