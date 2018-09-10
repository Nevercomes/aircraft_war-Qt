#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "bullet.h"

class PlayerBullet : public Bullet
{
public:
    PlayerBullet(qreal angle, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~PlayerBullet();
    void setBullet(int type);

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

private:
    int bullet_type;
};

#endif // PLAYERBULLET_H



