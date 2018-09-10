#include "playerPlane.h"

PlayerPlane::PlayerPlane(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    FlightVehicle(blood, w, h, speed, pixs, scene, parent),
    m_bomb(1), m_bullet(1), W(false), A(false), S(false), D(false) {
    setPos((scene->width() - m_w)/2, scene->height() - m_h);
    setFlag(QGraphicsItem::ItemIsFocusable);
    m_pixpos = 1;
}

PlayerPlane::~PlayerPlane() {

}

QRectF PlayerPlane::boundingRect() const
{
    return m_pixs.at(0).rect();
}

QPainterPath PlayerPlane::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void PlayerPlane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int PlayerPlane::name() const {
    return NAME_PLAYER_PLANE;
}

void PlayerPlane::advance(int) {
    m_step++;
    if(beingDestroyed){
        setFlag(QGraphicsItem::ItemIsMovable, false);
        setFlag(QGraphicsItem::ItemIsFocusScope, false);
        if(m_pixpos<m_pixs.size()-1 && m_step%STEP_DESTROY==0) {
            m_pixpos++;
            update();
            m_step = 0;
        }
    }
    if(m_pixpos == m_pixs.size()-1 && m_step%STEP_DESTROY==0)  destroy();

    if(!beingDestroyed){
        if (W && checkPos(UP)) {
            m_pixpos = 0;
            QPointF pos = scenePos();
            pos.ry() -= m_speed;
            setPos(pos);
        }
        if (S && checkPos(DOWN)) {
            m_pixpos = 1;
            QPointF pos = scenePos();
            pos.ry() += m_speed;
            setPos(pos);
        }
        if (A && checkPos(LEFT)) {
            m_pixpos = 1;
            QPointF pos = scenePos();
            pos.rx() -= m_speed;
            setPos(pos);
        }
        if (D && checkPos(RIGHT)) {
            m_pixpos = 1;
            QPointF pos = scenePos();
            pos.rx() += m_speed;
            setPos(pos);
        }
        if (!W && !S && !A && !D) m_pixpos = 1;
    }

    doCollide();
}

void PlayerPlane::posLost() {

}

void PlayerPlane::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case NAME_ENEMY_PLANE:
                flyer->fall();
                m_bullet = 1;
                if(m_blood != 0) m_blood = 1;
                emit sig_blood(m_blood);
                if (m_blood == 0) {
                    fall();
                }
                break;
            case NAME_ENEMY_BULLET:
                flyer->fall();
                m_bullet = 1;
                m_blood--;
                emit sig_blood(m_blood);
                if (m_blood == 0) {
                    fall();
                }
                break;
            case NAME_SUPPLY_BLOOD:
                flyer->fall();
                if (m_blood < UP_PLAYER_PLANE_BLOOD) {
                    m_blood++;
                    emit sig_blood(m_blood);
                }
                break;
            case NAME_SUPPLY_BOMB:
                flyer->fall();
                if (m_bomb < UP_PLAYER_BOMB) {
                    m_bomb++;
                    emit sig_bomb(m_bomb);
                }
                break;
            case NAME_SUPPLY_BULLET:
                flyer->fall();
                m_bullet = 2;
                break;
            }
        }
    }
}

void PlayerPlane::fall()
{
    beingDestroyed = true;
//    setFlag(QGraphicsItem::ItemIsMovable, false);
//    setFlag(QGraphicsItem::ItemIsFocusScope, false);
//    setVisible(false);
//    deleteLater();

}

void PlayerPlane::strike() {
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case NAME_ENEMY_PLANE:
                m_blood--;
                break;
            case NAME_ENEMY_BULLET:
                flyer->fall();
                if (m_blood == 0) {
                    m_bomb = 0;
                    fall();
                }
            }
        }
    }
}

void PlayerPlane::shoot()
{
    BulletFactory::PlayerBullets bullets = BulletFactory::pcreator(m_bullet, scene());
    QPointF pos = scenePos();
    pos.rx() += m_w/2 - SIZE_PLAYER_BULLET;
    foreach (PlayerBullet* bullet, bullets)
    {
        bullet->setPos(pos);
        bullet->setBullet(m_bullet);
    }
}

void PlayerPlane::bang()
{
    if(m_bomb >= 1){
        m_bomb--;
        emit sig_bomb(m_bomb);
        BulletFactory::Bombs bombs = BulletFactory::bcreator(1, scene());
//        QPointF pos = scenePos();
//        qDebug() << pos;
//        foreach (Bomb* bomb, bombs)
//        {
//            bomb->setPos(pos);
//        }
    }
}

void PlayerPlane::destroy()
{
    emit sig_fall();
//    deleteLater();
}

void PlayerPlane::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = true;
        break;
    case Qt::Key_S:
        event->accept();
        S = true;
        break;
    case Qt::Key_A:
        event->accept();
        A = true;
        break;
    case Qt::Key_D:
        event->accept();
        D = true;
        break;
    case Qt::Key_J:
        event->accept();
        shoot();
        break;
    case Qt::Key_K:
        event->accept();
        bang();
        break;
    default:
        event->ignore();
        break;
    }
}

void PlayerPlane::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_W:
        event->accept();
        W = false;
        break;
    case Qt::Key_S:
        event->accept();
        S = false;
        break;
    case Qt::Key_A:
        event->accept();
        A = false;
        break;
    case Qt::Key_D:
        event->accept();
        D = false;
        break;
    default:
        event->ignore();
        break;
    }
}

