#include "gun.h"
#include"bullet.h"
#include "qmath.h"
#include "game.h"
#include "player.h"
#include"pbullet.h"

extern Game *game;
extern player *pl;

gun::gun(int i, int j, QString bp)
{
    Damage=i;
    bulno=j;
    bulpix=bp;
}

void gun::fire()
{
    //bullet *b1=new bullet(":/pics/bullet2.png");
   // b1->setdmg(Damage);
   // b1->setPos(ps);
    //b1->setRotation(rot);
    //game->scene->addItem(b1);
    if(bulno==1){
        pbullet *b=new pbullet(bulpix);
        b->setdmg(Damage);
        b->setPos(pl->pos().x()+((pl->pixmap().width()/2)-20),pl->pos().y()+((pl->pixmap().height()/2)-15));

       b->setRotation(pl->rotation());
      // b->setPos(pl->pos().x()+50,pl->pos().y()+30);
       game->scene->addItem(b);



    }
    if(bulno==3){
        pbullet *b1=new pbullet(bulpix);
        pbullet *b2=new pbullet(bulpix);
        pbullet *b3=new pbullet(bulpix);

        b1->setPos(pl->pos().x()+60,pl->pos().y()+40);
        b1->setRotation(pl->rotation());
        b1->setdmg(Damage);

        game->scene->addItem(b1);
        b2->setPos(pl->pos().x()+60,pl->pos().y()+40);
        b2->setRotation(pl->rotation()-10);
        b2->setdmg(Damage);

        game->scene->addItem(b2);
        b3->setPos(pl->pos().x()+60,pl->pos().y()+40);
        b3->setRotation(pl->rotation()+10);
        b3->setdmg(Damage);

        game->scene->addItem(b3);



    }

   /* for(int gg=0;gg<bulno;gg++){
     bullet *b=new bullet(bulpix);

    b->setRotation(pl->rotation());
    b->setPos(pl->pos().x()+80,pl->pos().y()+40);
    game->scene->addItem(b);*/


    /*int jj=0;
    int jjj=1;
    b1->setRotation(rot+(10*jj*jjj));
    b1->setPos(ps);
    jjj*=-1;
    if((ii%2)==0)
        jj++;


    }*/}

int gun::returnDMG()
{
    return Damage;
}

void gun::upgr()
{
    if(bulno==1)
        Damage+=15;
    else
        Damage+=50;
}





