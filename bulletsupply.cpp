#include "bulletsupply.h"

BulletSupply::BulletSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    Supply(w, h, speed, pixs, scene, parent) {

}

BulletSupply::~BulletSupply() {

}


int BulletSupply::name() const {
    return NAME_SUPPLY_BULLET;
}
