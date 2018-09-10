#include "fish.h"

Fish::Fish(qreal angle, qreal blood, qreal w, qreal h, qreal speed, int type, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    EnemyPlane(angle, blood, w, h, speed, pixs, scene, parent), m_type(type) {

}

Fish::~Fish() {

}

void Fish::advance(int)
{
    if(beingDestroyed)
        if(m_pixpos < m_pixs.size()-1 && m_step%STEP_DESTROY==0)
            m_pixpos++;
    if(m_pixs.size() != 1 && m_pixpos == m_pixs.size()-1)  destroy();
    if(m_step == 0) {
        shoot();
    }

    m_step++;
    if (m_step % STEP_SHOOT_FISH == 0) {
        shoot();
    }
    if (m_step == STEP_SHOOT_FISH * 10) m_step = 0;
    QPointF pos = scenePos();
    if (!checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        posLost();
        return;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    doCollide();
}

void Fish::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            if (flyer->name() == NAME_PLAYER_BULLET) {
                flyer->fall();
                strike();
                if (m_blood <= 0) fall();
            }
            if(flyer->name() == NAME_PLAYER_BULLET_1){
                flyer->fall();
                m_blood -= 2;
                if (m_blood <= 0) fall();
            }
            if (flyer->name() == NAME_PLAYER_BOMB) {
                m_blood--; // 它是持续伤害
                if (m_blood <= 0) fall();
            }
        }
    }
}

void Fish::shoot()
{
    BulletFactory::EnemyBullets bullets = BulletFactory::ecreator(m_type, scene());
    QPointF pos = scenePos();
    switch (m_type) {
    case 1:
        pos.rx() += m_w - SIZE_FISH_BULLET;
        pos.ry() += m_h;
        break;
    case 2:
        pos.rx() += 60 - SIZE_FISH_BULLET_1;
        pos.ry() += m_h;
        break;
    case 3:
        pos.rx() += 110 - SIZE_FISH_BULLET_2;
        pos.ry() += 150;
        break;
    default:
        break;
    }


    foreach (EnemyBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}

void Fish::fall()
{
    beingDestroyed = true;
}

void Fish::destroy()
{
    int fishScore;
    switch (m_type) {
    case 1:
        fishScore = SCORE_FISH;
        break;
    case 2:
        fishScore = SCORE_FISH_1;
        break;
    case 3:
        fishScore = SCORE_FISH_2;
        break;
    default:
        break;
    }
    emit sig_score(fishScore);
    setVisible(false);
    deleteLater();
}



