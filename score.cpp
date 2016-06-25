/*#include <QFont>
#include <game.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <score.h>
extern player *pl;
extern Game *game;




void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}

void Score::setscore(int j)
{
    score=j;

    if(type==0){
    setPlainText(QString("Score: ") + QString::number(score));

    }
    else{
        setPlainText(QString("High Score:") + QString::number(score));

    }
}

Score::Score(int i, int t)
{
    score = i;
    type=t;

    // draw the text
    if(type==0){
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",16));
    setPos(game->pos());
    }
    else if(type==1){
        setPlainText(QString("High Score: ") + QString::number(score));
        setDefaultTextColor(Qt::blue);
        setFont(QFont("times",16));
        setPos(game->pos());
    }

}*/
