#include "bulletfactory.h"

BulletFactory::Bombs BulletFactory::bcreator(uint flag, QGraphicsScene *scene)
{
    Bombs temp;
    switch (flag) {
    case 0:
        break;
    case 1:
        QPixmaps t;
        t.append(QPixmap(IMG_PLAYER_BOMB));
        t.append(QPixmap(IMG_PLAYER_BOMB_1));
        t.append(QPixmap(IMG_PLAYER_BOMB_2));
        t.append(QPixmap(IMG_PLAYER_BOMB_3));
        t.append(QPixmap(IMG_PLAYER_BOMB_4));
        t.append(QPixmap(IMG_PLAYER_BOMB_5));
        temp.append(new Bomb(90, SIZE_PLAYER_BOMB, SIZE_PLAYER_BOMB, SPEED_PLAYER_BOMB, t, scene));
        break;
    }
    return temp;
}

BulletFactory::PlayerBullets BulletFactory::pcreator(uint flag, QGraphicsScene *scene)
{
    PlayerBullets temp;
    if (flag == 1) {
        QPixmaps t;
        t.append(QPixmap(IMG_PLAYER_BULLET));
        temp.append(new PlayerBullet(90, SIZE_PLAYER_BULLET, SIZE_PLAYER_BULLET, SPEED_PLAYER_BULLET, t, scene));
    }
    if (flag == 2) {
        QPixmaps t;
        t.append(QPixmap(IMG_PLAYER_BULLET_1));
        temp.append(new PlayerBullet(90, SIZE_PLAYER_BULLET, SIZE_PLAYER_BULLET, SPEED_PLAYER_BULLET, t, scene));
    }
    return temp;
}

BulletFactory::EnemyBullets BulletFactory::ecreator(uint flag, QGraphicsScene *scene)
{
    EnemyBullets temp;
    QPixmaps t, t1, t2;
    switch (flag) {
    case 0:
        break;
    case 1:
        t.append(QPixmap(IMG_FISH_BULLET));
        temp.append(new EnemyBullet(90, SIZE_FISH_BULLET, SIZE_FISH_BULLET, SPEED_FISH_BULLET, t, scene));
        break;
    case 2:
        t.append(QPixmap(IMG_FISH_BULLET_1));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, SIZE_FISH_BULLET_1, SIZE_FISH_BULLET_1, SPEED_FISH_BULLET_1, t, scene));
        }
        break;
    case 3:
        t.append(QPixmap(IMG_FISH_BULLET_2));
        for (int i = 0; i < 8; i++) {
            temp.append(new EnemyBullet(0 + 45 * i, SIZE_FISH_BULLET_2, SIZE_FISH_BULLET_2, SPEED_FISH_BULLET_2, t, scene));
        }
        break;

    case 4:
        t.append(QPixmap(IMG_BOSS_BULLET)); // 扩散
        for (int i = 0; i < 12; i++) {
            temp.append(new EnemyBullet(0 + 30 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET, t, scene));
        }
        break;
    case 5:
        t1.append(QPixmap(IMG_BOSS_BULLET)); // 加大密度 & 大子弹
        for (int i = 0; i < 12; i++) {
            temp.append(new EnemyBullet(0 + 30 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET, t1, scene));
        }
        t2.append(QPixmap(IMG_BOSS_BULLET_2));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET_1, t2, scene));
        }
        break;
    case 6:
        t1.append(QPixmap(IMG_BOSS_BULLET));
        for (int i = 0; i < 36; i++) {
            temp.append(new EnemyBullet(0 + 10 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET, t1, scene));
        }
        t2.append(QPixmap(IMG_BOSS_BULLET_2));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET_2, t2, scene));
        }
        break;
    case 7:
        t1.append(QPixmap(IMG_BOSS_BULLET));
        for (int i = 0; i < 36; i++) {
            temp.append(new EnemyBullet(0 + 10 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET_1, t1, scene));
        }
        t2.append(QPixmap(IMG_BOSS_BULLET_2));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, SIZE_BOSS_BULLET, SIZE_BOSS_BULLET, SPEED_BOSS_BULLET_2, t2, scene));
        }
        break;
    }
    return temp;
}
