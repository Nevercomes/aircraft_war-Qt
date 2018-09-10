#include "planefactory.h"

PlaneFactory::BossPlanes PlaneFactory::bcreator(uint flag, QGraphicsScene *scene)
{
    BossPlanes temp;
    switch (flag) {
    case 1:
        QPixmaps t;
        t.append(QPixmap(IMG_BOSS1));
        t.append(QPixmap(IMG_BOSS1_1));
        t.append(QPixmap(IMG_BOSS1_2));
        t.append(QPixmap(IMG_BOSS1_3));
        t.append(QPixmap(IMG_BOSS1_4));
        int angle = Randomizer::creat(180);
        temp.append(new Boss(angle, HP_BOSS, SIZE_BOSS, SIZE_BOSS, SPEED_BOSS, t, scene));
    }
    return temp;
}

PlaneFactory::FishPlanes PlaneFactory::fcreator(uint flag, QGraphicsScene *scene)
{
    FishPlanes temp;
    for (uint i = 0; i < flag; i++)
    {
        QPixmaps t;
        t.append(QPixmap(IMG_FISH1));
        t.append(QPixmap(IMG_FISH1_1));
        t.append(QPixmap(IMG_FISH1_2));
        t.append(QPixmap(IMG_FISH1_3));
        t.append(QPixmap(IMG_FISH1_4));
//        int angle = Randomizer::creat(180);
        temp.append(new Fish(90, HP_FISH, SIZE_FISH, SIZE_FISH, SPEED_FISH, 1, t, scene));
    }
    return temp;
}

PlaneFactory::FishPlanes PlaneFactory::fcreator_two(uint flag, QGraphicsScene *scene)
{
    FishPlanes temp;
    for (uint i = 0; i < flag; i++)
    {
        QPixmaps t;
        t.append(QPixmap(IMG_FISH2));
        t.append(QPixmap(IMG_FISH2_1));
        t.append(QPixmap(IMG_FISH2_2));
        t.append(QPixmap(IMG_FISH2_3));
        t.append(QPixmap(IMG_FISH2_4));
        t.append(QPixmap(IMG_FISH2_5));
        temp.append(new Fish(90, HP_FISH_1, SIZE_FISH_1, SIZE_FISH_1, SPEED_FISH, 2, t, scene));
    }
    return temp;
}

PlaneFactory::FishPlanes PlaneFactory::fcreator_three(uint flag, QGraphicsScene *scene)
{
    FishPlanes temp;
    for (uint i = 0; i < flag; i++)
    {
        QPixmaps t;
        t.append(QPixmap(IMG_FISH3));
        t.append(QPixmap(IMG_FISH3_1));
        t.append(QPixmap(IMG_FISH3_2));
        t.append(QPixmap(IMG_FISH3_3));
        t.append(QPixmap(IMG_FISH3_4));
        t.append(QPixmap(IMG_FISH3_5));
        t.append(QPixmap(IMG_FISH3_6));
        t.append(QPixmap(IMG_FISH3_7));
        t.append(QPixmap(IMG_FISH3_8));
        temp.append(new Fish(90, HP_FISH_2, SIZE_FISH_2, SIZE_FISH_2, SPEED_FISH_2, 3, t, scene));
    }
    return temp;
}
