#include "bombsupply.h"

BombSupply::BombSupply(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    Supply(w, h, speed, pixs, scene, parent) {

}

BombSupply::~BombSupply() {

}

int BombSupply::name() const {
    return NAME_SUPPLY_BOMB;
}
