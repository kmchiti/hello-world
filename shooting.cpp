/*#include "shooting.h"
#include <QList>
#include "QTimer"
#include <QString>
#include "player.h"
#include "game.h"
#include
extern player* pls;

shooting::shooting(QPointF a)
{
   setPixmap(QPixmap(":/pics/shooting.png"));
   setPos(a);
   QTimer*time=new QTimer(this);
   connect(time,SIGNAL(timeout()),this,SLOT(shoot()));

   time->start(30);




}

void shooting::shoot()
{
    ebullet* b=new ebullet(":/pics/bullet1.png");
    b->rotate(pl->pos());
    b->setPos(this->pos());

}*/
