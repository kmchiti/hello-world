#ifndef ENEMY
#define ENEMY


#include <QPointF>
#include "object.h"



class enemy: public object {
    Q_OBJECT


protected:
    int coldmg;
public:
    enemy();
    void DEC(int i);

};






#endif // ENEMY

