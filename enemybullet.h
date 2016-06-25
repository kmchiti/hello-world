#ifndef ENEMYBULLET
#define ENEMYBULLET

#include "bullet.h"




class ebullet:public bullet{
    Q_OBJECT

public:
    ebullet(QString s=QString(":/pics/bullet1.png"));
public slots:
    void move();











};








#endif // ENEMYBULLET

