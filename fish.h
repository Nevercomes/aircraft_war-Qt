#ifndef FISH_H
#define FISH_H

#include "enemyplane.h"
#include "randomizer.h"

class Fish : public EnemyPlane
{
public:
    Fish(qreal angle, qreal blood, qreal w, qreal h, qreal speed, int type, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Fish();

    // QGraphicsItem interface
public:
    void advance(int phase);

    // Flyer interface
public:
    void doCollide();
    void fall();

    // FlightVehicle interface
public:
    void shoot();
    void destroy();

protected:
   int m_type;
};

#endif // FISH_H
