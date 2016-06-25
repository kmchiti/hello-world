#ifndef GUN
#define GUN


//#include "player.h"/*/////////////////////////////may cause problems////////*/
#include <QObject>
#include <QString>
#include <QPointF>
#include"pbullet.h"
#include "bullet.h"
#include "enemy.h"


class gun:public QObject{
    Q_OBJECT
    int Damage;
    int bulno;
    QString bulpix;

public:
    gun(int i,int j,QString bp);
    void fire();
    int returnDMG();
    void upgr();
    //void fire(QPointF ps,qreal rot);

};








#endif // GUN

