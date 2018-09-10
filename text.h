#ifndef TEXT_H
#define TEXT_H

#include "unflyer.h"

class Text : public UnFlyer
{
public:
    Text(qreal w, qreal h, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Text();

    // QGraphicsItem interface
public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal m_w, m_h;
    QPixmaps m_pixs;
    qreal m_pixpos;
};

#endif // TEXT_H
