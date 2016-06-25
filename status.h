#ifndef STATUS
#define STATUS


#include <QGraphicsTextItem>
#include "game.h"
#include "player.h"



class status:public QGraphicsTextItem{
    int type;
    int amount;
public:
    status(int t, int a);
    void set(int ii);







};





#endif // STATUS

