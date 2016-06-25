#ifndef WALKING
#define WALKING


#include <QGraphicsItem>
#include <enemy.h>




class walking:public enemy{
    Q_OBJECT



    int speed;



public:
    walking(QPointF a,int spd=100, int lv=1, QString  pix=":/pics/walker.png");
    void dechp(int i);
public slots:
    void move();






};






#endif // WALKING

