#ifndef TOWER1
#define TOWER1
#include<tower.h>

class Tower1:public Tower
{
    Q_OBJECT
public:
    Tower1(QGraphicsItem* parent=0);
    void fire();
public slots:
    void aquire_target();

};

#endif // TOWER1

