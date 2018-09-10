#include "playerbullet.h"

PlayerBullet::PlayerBullet(qreal angle, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(angle, w, h, speed, pixs, scene, parent), bullet_type(1) {

}

PlayerBullet::~PlayerBullet() {

}

void PlayerBullet::setBullet(int type)
{
    bullet_type = type;
}

QRectF PlayerBullet::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath PlayerBullet::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void PlayerBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int PlayerBullet::name() const
{
    if(bullet_type == 1)
        return NAME_PLAYER_BULLET;
    else if(bullet_type == 2)
        return NAME_PLAYER_BULLET_1;
}

void PlayerBullet::advance(int)
{
    if (!checkPos(UP) || !checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        posLost();
        return;
    }
    QPointF pos = scenePos();
    pos.rx() -= xSpeed;
    pos.ry() -= ySpeed;
    setPos(pos);
}

void PlayerBullet::posLost() {
    setVisible(false);
    deleteLater();
}

void PlayerBullet::doCollide() {

}

void PlayerBullet::fall() {
    setVisible(false);
    deleteLater();
}

//void PlayerBullet::slt_bulletType(int type)
//{
//    bullet_type = type;
//}
