#ifndef BULLET
#define BULLET



#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QString>
#include <QPointF>
//#include "score.h"
#include <QLineF>
class bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
protected:
    int dmg;
public:
    void setdmg(int i);
    bullet(QString s=QString(":/pics/bullet1.png"));
    void rotate(QPointF p);
    int returndmg();

public slots:
    virtual void move()=0;




};










#endif // BULLET



