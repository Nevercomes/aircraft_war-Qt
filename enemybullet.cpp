#include "enemybullet.h"

EnemyBullet::EnemyBullet(qreal angle, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(angle, w, h, speed, pixs, scene, parent){

}

EnemyBullet::~EnemyBullet() {

}

QRectF EnemyBullet::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath EnemyBullet::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void EnemyBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(0));
}

int EnemyBullet::name() const
{
    return NAME_ENEMY_BULLET;
}

void EnemyBullet::advance(int)
{
    if (!checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) { // 取消上边界
        posLost();
        return;
    }
    QPointF pos = scenePos();
    pos.rx() += xSpeed;
    pos.ry() += ySpeed;
    setPos(pos);
}

void EnemyBullet::posLost() {
    setVisible(false);
    deleteLater();
}

void EnemyBullet::doCollide() {

}

void EnemyBullet::fall() {
    setVisible(false);
    deleteLater();
}
