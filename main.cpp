#include "mainwindow.h"
#include <QApplication>
#include <game.h>
#include"button.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include"player.h"
#include<QGraphicsTextItem>
#include <QString>
#include <QFile>
#include <QTextStream>
#include<QGraphicsPixmapItem>

Game *game;
QGraphicsScene* scene;
QGraphicsView* view;
extern player* pl;
QGraphicsScene* scene_over;
QGraphicsTextItem* text2;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //game=new Game();

    scene=new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":pics/back1.png")));
    scene->setSceneRect(0,0,1851,1195);
    Button* button = new Button(1,"START");
    button->setPos(1200,1000);
    scene->addItem(button);


    Button* button2 = new Button(0,"QUIT");
    button2->setPos(1200,1100);
    scene->addItem(button2);



    QFile file("s.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    int III=0;
    QTextStream in(&file);
    in>>III;
    file.close();


    QGraphicsTextItem* text=new QGraphicsTextItem("tets",0);
    text->setPlainText(QString("High score:  ") + QString::number(III));
    text->setDefaultTextColor(Qt::white);
    text->setFont(QFont("times",24));
    text->setPos(1200,870);
    scene->addItem(text);
    text->show();

    scene_over=new QGraphicsScene();
    scene_over->setBackgroundBrush(QBrush(QImage(":pics/dirt1.png")));
    scene_over->setSceneRect(0,0,800,600);
    Button* button3 = new Button(0,"QUIT");
    button3->setPos(270,400);
    scene_over->addItem(button3);

    text2=new QGraphicsTextItem("tets",0);
    text2->setPlainText(QString("GAME OVER") +QString("\n score:") + QString::number(III)) ;
    text2->setDefaultTextColor(Qt::white);
    text2->setFont(QFont("times",32));
    text2->setPos(270,150);
    scene_over->addItem(text2);

    view=new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();



    //game->showFullScreen();


    return a.exec();
}
