#ifndef BULLETSUPPLY_H
#define BULLETSUPPLY_H

#include "supply.h"

class BulletSupply : public Supply
{
public:
    BulletSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~BulletSupply();
    int name() const;
};

#endif // BULLETSUPPLY_H
