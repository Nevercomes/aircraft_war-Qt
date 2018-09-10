#include "boss.h"

Boss::Boss(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    EnemyPlane(angle, blood, w, h, speed, pixs, scene, parent), flag(1) {

}

Boss::~Boss() {

}

void Boss::advance(int)
{
    m_step++;
//    if (m_step % STEP_BOSS_PIX == 0) { // change
//        if (flag == 1 && m_pixpos == m_pixs.size() - 1) flag = -1;
//        else if (flag == -1 && m_pixpos == 0) flag = 1;
//        m_pixpos += flag;
//        m_step = 0;
//    }

    if (1.0 * HP_BOSS * 3 / 4 < m_blood && m_blood <= HP_BOSS)
        m_pixpos = 0; // 3/4 - 1
    else if (1.0 * HP_BOSS * 2 / 4 < m_blood && m_blood <= 1.0 * HP_BOSS * 3 / 4)
        m_pixpos = 1; // 2/4 -3/4
    else if (1.0 * HP_BOSS * 1 / 4 < m_blood && m_blood <= 1.0 * HP_BOSS * 2 / 4)
        m_pixpos = 2; // 1/4 - 2/4
    else if (0 < m_blood && m_blood <= 1.0 * HP_BOSS * 1 / 4)
        m_pixpos = 3; // 0 - 1/4


    if (m_step % STEP_SHOOT_BOSS == 0) {
        shoot();
    }

    if (m_step == STEP_SHOOT_BOSS * 1000) m_step = 0;

    QPointF pos = scenePos();
    if (!checkPos(UP) || pos.ry()>SIZE_HEIGHT_SCENE/2-m_h) {
        y_speed = -y_speed;
    }
    if (!checkPos(LEFT) || !checkPos(RIGHT)) {
        x_speed = -x_speed;
    }

    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    doCollide();
}

void Boss::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            if (flyer->name() == NAME_PLAYER_BULLET) {
                flyer->fall();
                strike();
                if (m_blood <= 0) fall();
            }

            if (flyer->name() == NAME_PLAYER_BULLET_1) {
                flyer->fall();
                m_blood -= 2;
                if (m_blood <= 0) fall();
            }

            if (flyer->name() == NAME_PLAYER_BOMB) {
                m_blood--;
                if (m_blood <= 0) fall();
            }
        }
    }
}

void Boss::fall()
{
//    setVisible(false);
    // dead but not disappear
    m_pixpos = 4;
    x_speed = 0;
    y_speed = 0;
    deleteLater();
    emit sig_score(SCORE_BOSS);
}

void Boss::shoot()
{
    int temp;
    if (1.0 * HP_BOSS * 3 / 4 < m_blood && m_blood <= HP_BOSS) temp = 4; // 3/4 - 1
    else if (1.0 * HP_BOSS * 2 / 4 < m_blood && m_blood <= 1.0 * HP_BOSS * 3 / 4) temp = 5; // 2/4 -3/4
    else if (1.0 * HP_BOSS * 1 / 4 < m_blood && m_blood <= 1.0 * HP_BOSS * 2 / 4) temp = 6; // 1/4 - 2/4
    else if (0 < m_blood && m_blood <= 1.0 * HP_BOSS * 1 / 4) temp = 7; // 0 - 1/4
    // shoot as hp
    BulletFactory::EnemyBullets bullets = BulletFactory::ecreator(temp, scene());
    QPointF pos = scenePos();

    int bulletsize = SIZE_BOSS_BULLET;
//    if (temp == 5 || temp == 6 || temp == 7) bulletsize = SIZE_BOSS / 2;
    pos.rx() += m_w / 2 - bulletsize / 2;
    pos.ry() += m_h / 2;
    foreach (EnemyBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}

void Boss::destroy()
{

}


