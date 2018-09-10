#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H

#include "boss.h"
#include "fish.h"
#include "randomizer.h"

class PlaneFactory
{
public:
    typedef QList<Boss*> BossPlanes;
    typedef QList<Fish*> FishPlanes;
    static BossPlanes bcreator(uint flag, QGraphicsScene *scene);
    static FishPlanes fcreator(uint flag, QGraphicsScene *scene);
    static FishPlanes fcreator_two(uint flag, QGraphicsScene *scene);
    static FishPlanes fcreator_three(uint flag, QGraphicsScene *scene);
};

#endif // PLANEFACTORY_H
