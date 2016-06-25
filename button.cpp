#include"button.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QBrush>
#include <QGraphicsTextItem>
#include<QDebug>
#include"game.h"

extern QGraphicsScene* scene;
//extern QGraphicsScene* scene2;
extern QGraphicsView* view;
//extern QGraphicsScene* scene3;
extern Game* game;

Button::Button(int id, QString name)
{
    //draw rect
    setRect(0,0,200,50);
    QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkCyan);
        setBrush(brush);

     // draw the text
     text = new QGraphicsTextItem(name,this);
     int xPos = rect().width()/2 - text->boundingRect().width()/2;
     int yPos = rect().height()/2 - text->boundingRect().height()/2;
     text->setPos(xPos,yPos);
    ID=id;
    setAcceptHoverEvents(true);

}

Button::Button(int id)
{
    //draw rect
    setRect(0,0,200,50);
    QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkCyan);
        setBrush(brush);

     // draw the text
     text = new QGraphicsTextItem("test",this);
     int xPos = rect().width()/2 - text->boundingRect().width()/2;
     int yPos = rect().height()/2 - text->boundingRect().height()/2;
     text->setPos(xPos,yPos);


    ID=id;

    setAcceptHoverEvents(true);

}


void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(ID==1){
        //view->setScene(scene2);
        game=new Game();
        game->showFullScreen();

    }
    else if (ID==0){
        exit(0);
    }
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    /*qDebug()<<"hevr\n";
    text2=new QGraphicsTextItem("tets",this);
    text2->setPos(pos());
    text2->show();*/

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //text2->hide();
}



