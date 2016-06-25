#ifndef PBULLET
#define PBULLET






#include "bullet.h"




class pbullet:public bullet{
    Q_OBJECT

public:
    pbullet(QString s=QString(":/pics/bullet1.png"));
public slots:
    void move();











};

#endif // PBULLET

