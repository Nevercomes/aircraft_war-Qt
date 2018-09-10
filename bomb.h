#ifndef PLAYERBOMB_H
#define PLAYERBOMB_H

#include "bullet.h"
#include "enemybullet.h"

class Bomb : public Bullet
{
public:
    Bomb(qreal angel, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Bomb();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;
    void advance(int);

    // Flyer interface
public:
    int name() const;
    void posLost();
    void doCollide();
    void fall();
};

#endif // BOMB_H
