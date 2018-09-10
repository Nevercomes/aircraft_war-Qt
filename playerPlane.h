#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "flightvehicle.h"
#include "bulletfactory.h"

class PlayerPlane : public FlightVehicle
{
public:
    PlayerPlane(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~PlayerPlane();

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

    // FlightVehicle interface
public:
    void strike();
    void shoot();
    void destroy();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void bang();

private:
    int m_bullet, m_bomb;
    bool W, A, S, D;
};

#endif // PLAYERPLANE_H
