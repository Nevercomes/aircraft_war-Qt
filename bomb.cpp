#include "bomb.h"

Bomb::Bomb(qreal angel, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(angel, w, h, speed, pixs, scene, parent) {
    setPos((scene->width() - m_w)/2, (scene->height() - m_h)/2);
}

Bomb::~Bomb() {

}

QRectF Bomb::boundingRect() const {
    QRect rect(0, 0, SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE); // whole screen
    return rect;
}

QPainterPath Bomb::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int Bomb::name() const
{
    return NAME_PLAYER_BOMB;
}

void Bomb::advance(int)
{
    m_step++;
    if (m_step == STEP_BOMB_PIX && m_pixpos < m_pixs.size()-1) {
        m_step = 0;
        m_pixpos++;
        update();
    }
    if(m_step == STEP_BOMB_PIX && m_pixpos == m_pixs.size()-1)
        fall();

    QPointF pos = scenePos();
    setPos(pos);
    doCollide();
}

void Bomb::posLost() {
//    setVisible(false);
//    deleteLater();
}

void Bomb::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case NAME_ENEMY_BULLET:
                flyer->fall();
                break;
            }
        }
    }
}

void Bomb::fall() {
    setVisible(false);
    deleteLater();
}
