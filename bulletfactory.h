#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "bomb.h"
#include "playerbullet.h"
#include "enemybullet.h"

class BulletFactory
{
public:
    typedef QList<Bomb*> Bombs;
    typedef QList<PlayerBullet*> PlayerBullets;
    typedef QList<EnemyBullet*> EnemyBullets;
    static Bombs bcreator(uint flag, QGraphicsScene *scene);
    static PlayerBullets pcreator(uint flag, QGraphicsScene *scene);
    static EnemyBullets ecreator(uint flag, QGraphicsScene *scene);

};

#endif // BULLETFACTORY_H
