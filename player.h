#ifndef PLAYER
#define PLAYER
#include "gun.h"
#include "object.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <game.h>
#include <QMouseEvent>
#include <QMediaPlayer>
#include <QString>
//#include "score.h"
//extern QPointF ppo;



class player:public object{
    Q_OBJECT

public:
    QMediaPlayer *RI;
    QMediaPlayer *SHO;
    gun* rifle;
    gun* shot;
    void shoot();
    player(int lv=1,int mny=0,int ar=10,int ex=0,QString  pix=":/pics/rifle.png");
    void keyPressEvent(QKeyEvent * event);
    int returnhp();
    int returnammo();
    int returnxp();
    int returnlvl();
    void dechp(int i);
    int returndmg();
    void EXPE(int i);
    void setmoney(int i);
    int returnmoney();
    void upgrd(int i);

    int scor;
    bool end;

private:
    int money;
    int gtype;
    int experience;
    int AMMO;

    int maxhp;

};

#endif // PLAYER

