#ifndef BUTTON
#define BUTTON

#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>

class Button:public QGraphicsRectItem
{
public:
    Button(int id,QString name);
    Button(int id);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

private:
    QGraphicsTextItem* text;
    QGraphicsTextItem* text2;
    int ID;

};

#endif // BUTTON

