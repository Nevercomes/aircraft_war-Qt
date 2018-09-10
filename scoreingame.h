#ifndef SCOREINGAME_H
#define SCOREINGAME_H

#include <QGraphicsTextItem>

#include "unflyer.h"

class ScoreInGame : public UnFlyer
{
public:
    ScoreInGame(qreal w, qreal h, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~ScoreInGame();
    void setScore(int score);

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int);

protected:
    qreal m_w, m_h;
    int score;
    QFont font;
};

#endif // SCOREINGAME_H
