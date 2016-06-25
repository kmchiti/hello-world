#ifndef OBJECT
#define OBJECT


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
#include <QString>
#include <string>
#include <string.h>
#include <QLineF>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QLineF>
//QPointF ppo;

class object: public QObject, public QGraphicsPixmapItem{
   // Q_OBJECT

public:

    void rotate(QPointF p,int i,int j);
    int type;

protected:
    int health;
    int armor;
    int lvl;
    QString s;

};

#endif // OBJECT

