#ifndef BULLET_H
#define BULLET_H

#include "flyer.h"
#include "unflyer.h"
#include <math.h>

#define ROTATE 57.26

class Bullet : public Flyer
{
public:
    Bullet(qreal angle,
           qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0)
        :Flyer(w, h, speed, pixs, scene, parent),
         m_angle(angle),
         xSpeed(::cos(m_angle / ROTATE) * m_speed),
         ySpeed(::sin(m_angle / ROTATE) * m_speed) {

    }
    virtual ~Bullet() {

    }

protected:
    qreal m_angle, xSpeed, ySpeed;
};

#endif // BULLET_H


