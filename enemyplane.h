#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "flightvehicle.h"
#include "bulletfactory.h"

class EnemyPlane : public FlightVehicle
{
public:
    EnemyPlane(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~EnemyPlane();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

    // Flyer interface
public:
    int name() const;
    void posLost();

    // FlightVehicle interface
public:
    void strike();

protected:
    qreal m_angle, x_speed, y_speed;

};

#endif // ENEMYPLANE_H
