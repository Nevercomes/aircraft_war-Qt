#ifndef STATUS_H
#define STATUS_H

#include <QPixmap>

#include "unflyer.h"
#include "global.h"

class Status : public UnFlyer
{
public:
    Status(qreal w, qreal h, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Status();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void advance(int);

protected:
    qreal m_w, m_h;
    QPixmaps m_pixs;
    qreal m_pixpos;

};

#endif // STATUS_H
