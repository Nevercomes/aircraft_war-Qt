#ifndef BOMBSUPPLY_H
#define BOMBSUPPLY_H

#include "supply.h"

class BombSupply : public Supply
{
public:
    BombSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~BombSupply();
    int name() const;
};

#endif // BOMBSUPPLY_H
