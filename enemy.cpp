#include "enemy.h"
#include <QGraphicsScene>


enemy::enemy()
{
    coldmg=0;
}

void enemy::DEC(int i)
{
    health-=i;

}

