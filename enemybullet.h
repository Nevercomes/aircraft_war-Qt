#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "bullet.h"
#include <math.h>

#define ROTATE 57.26

class EnemyBullet : public Bullet
{
public:
    EnemyBullet(qreal angle, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~EnemyBullet();

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

#endif // ENEMYBULLET_H
