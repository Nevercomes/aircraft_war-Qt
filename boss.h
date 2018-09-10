#ifndef BOSS_H
#define BOSS_H

#include "enemyplane.h"

class Boss : public EnemyPlane
{
public:
    Boss(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Boss();

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

private:
    int flag; // Ãÿ ‚øÿ÷∆bossÕº∆¨±‰ªª
};

#endif // BOSS_H
