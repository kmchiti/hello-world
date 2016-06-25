#include "object.h"


void object::rotate(QPointF p,int i,int j)
{


    const QPointF b(pos().x()+i,pos().y()+j);

    QLineF l(b,p);

    setRotation(-1 * l.angle());
}
