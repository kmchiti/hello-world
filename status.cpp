#include "status.h"
#include "game.h"
#include "player.h"
extern Game *game;
extern player *pl;

status::status(int t, int a)
{
    type=t;
    amount=a;
    if(type==0){
    setPlainText(QString("HP:") + QString::number(amount));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    this->setPos((qreal)pl->pos().x(),(qreal)pl->pos().y()-10);
    //setPos(pl->pos().x(),pl->pos.y()-10);
   // setPos(pl->pos().x(),pl->pos.y()-10);
    }
    else if(type==1){
        setPlainText(QString("ammo:") + QString::number(amount));
        setDefaultTextColor(Qt::blue);
        setFont(QFont("times",16));
        setPos(pl->pos().x(),pl->pos().y()-30);
    }
    else if(type==2){
        setPlainText(QString("EXP") + QString::number(amount));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("times",16));
        setPos(pl->pos().x()+100,pl->pos().y()-10);
    }
    else if(type==3){
        setPlainText(QString("LVL") + QString::number(amount));
        setDefaultTextColor(Qt::white);
        setFont(QFont("times",16));
        setPos(pl->pos().x()+100,pl->pos().y()-30);
    }
    else if(type==4){
        setPlainText(QString("money") + QString::number(amount));
        setDefaultTextColor(Qt::white);
        setFont(QFont("times",16));
        setPos(pl->pos().x(),pl->pos().y()+70);
    }
}

void status::set(int ii)
{
    amount=ii;
    if(type==0){
    setPlainText(QString("HP:") + QString::number(amount));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    this->setPos((qreal)pl->pos().x(),(qreal)pl->pos().y()-10);
    //setPos(pl->pos().x(),pl->pos.y()-10);
   // setPos(pl->pos().x(),pl->pos.y()-10);
    }
    else if(type==1){
        setPlainText(QString("ammo:") + QString::number(amount));
        setDefaultTextColor(Qt::blue);
        setFont(QFont("times",16));
        setPos(pl->pos().x(),pl->pos().y()-30);
    }
    else if(type==2){
        setPlainText(QString("EXP") + QString::number(amount));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("times",16));
        setPos(pl->pos().x()+100,pl->pos().y()-10);
    }
    else if(type==3){
        setPlainText(QString("LVL") + QString::number(amount));
        setDefaultTextColor(Qt::white);
        setFont(QFont("times",16));
        setPos(pl->pos().x()+100,pl->pos().y()-30);
    }
    else if(type==4){
        setPlainText(QString("money") + QString::number(amount));
        setDefaultTextColor(Qt::white);
        setFont(QFont("times",16));
        setPos(pl->pos().x(),pl->pos().y()+70);
    }

}
