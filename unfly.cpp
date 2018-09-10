#include "unflyer.h"

UnFlyer::UnFlyer(QGraphicsItem *parent) : QGraphicsObject(parent) {

}

UnFlyer::~UnFlyer() {

}

int UnFlyer::type() const {
    return UserType + 1;
}
