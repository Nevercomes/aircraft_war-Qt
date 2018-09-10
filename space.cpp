#include "space.h"

Space::Space(QWidget *parent) : QGraphicsView(parent), boss(false),  isRunning(false), isWaiting(false) {
    m_scene = new QGraphicsScene;
    m_scene->setSceneRect(0, 0, SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE);
    setScene(m_scene);

    setWindowFlags(Qt::FramelessWindowHint);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setOptimizationFlags(QGraphicsView::DontClipPainter | QGraphicsView::DontSavePainterState);
    setRenderHint(QPainter::Antialiasing);

    QPixmap pix(SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE);
    pix.load(IMG_BACKGROUND);
    QPixmap temp = pix.scaled(SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE, Qt::KeepAspectRatioByExpanding);
    setBackgroundBrush(temp);

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(slt_updata()));
    connect(this, SIGNAL(sig_menu()), this, SLOT(slt_menu()));

    m_playList = new QMediaPlaylist;
    m_music = new QMediaPlayer;
    m_playList->addMedia(QUrl(SOUND_BATTLE_NORMAL_BG));
    m_playList->addMedia(QUrl(SOUND_BATTLE_BOSS_BG));
    m_playList->setCurrentIndex(0);
    m_playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    m_music->setPlaylist(m_playList);
    init();
}

void Space::init()
{
    m_scores = 0, m_bloods = UP_PLAYER_PLANE_BLOOD, m_bombs = 1, m_level = 1, m_round = 0, m_step = 0;
    bigFish = 1;
    QPixmaps airPix;
    airPix.append(QPixmap(IMG_PLAYER_PLANE));
    airPix.append(QPixmap(IMG_PLAYER_PLANE_1));
    airPix.append(QPixmap(IMG_PLAYER_PLANE_2));
    airPix.append(QPixmap(IMG_PLAYER_PLANE_3));
    airPix.append(QPixmap(IMG_PLAYER_PLANE_4));
    m_player = new PlayerPlane(UP_PLAYER_PLANE_BLOOD, SIZE_PLAYER_PLANE, SIZE_PLAYER_PLANE, SPEED_PLAYER_PLANE, airPix, m_scene);
    m_player->setFocus();
//    connect(m_player, SIGNAL(sig_score(int)), this, SLOT(slt_updateScore(int)));
    connect(m_player, SIGNAL(sig_blood(int)), this, SLOT(slt_updateBlood(int)));
    connect(m_player, SIGNAL(sig_bomb(int)), this, SLOT(slt_updateBomb(int)));
    connect(m_player, SIGNAL(sig_fall()), this, SLOT(slt_playerDead()));

    // Status
    QPixmaps bloodPix;
    bloodPix.append(QPixmap(IMG_STATUS_BLOOD));
    bloodPix.append(QPixmap(IMG_STATUS_BLOOD_1));
    SIZE_STATUS_BLOOD1 = new Status(SIZE_STATUS_BLOOD, SIZE_STATUS_BLOOD, bloodPix, m_scene);
    SIZE_STATUS_BLOOD2 = new Status(SIZE_STATUS_BLOOD, SIZE_STATUS_BLOOD, bloodPix, m_scene);
    SIZE_STATUS_BLOOD3 = new Status(SIZE_STATUS_BLOOD, SIZE_STATUS_BLOOD, bloodPix, m_scene);
    SIZE_STATUS_BLOOD1->setPos(20, 110);
    SIZE_STATUS_BLOOD2->setPos(60, 110);
    SIZE_STATUS_BLOOD3->setPos(100, 110);
    SIZE_STATUS_BLOOD1->setZValue(1);
    SIZE_STATUS_BLOOD2->setZValue(1);
    SIZE_STATUS_BLOOD3->setZValue(1);

    QPixmaps bombStatusPix;
    bombStatusPix.append(QPixmap(IMG_STATUS_BOMB));
    bombStatus1 = new Status(SIZE_STATUS_BOMB, SIZE_STATUS_BOMB, bombStatusPix, m_scene);
    bombStatus2 = new Status(SIZE_STATUS_BOMB, SIZE_STATUS_BOMB, bombStatusPix, m_scene);
    bombStatus3 = new Status(SIZE_STATUS_BOMB, SIZE_STATUS_BOMB, bombStatusPix, m_scene);
    bombStatus1->setPos(20, SIZE_HEIGHT_SCENE-SIZE_STATUS_BOMB-20);
    bombStatus2->setPos(70, SIZE_HEIGHT_SCENE-SIZE_STATUS_BOMB-20);
    bombStatus3->setPos(120, SIZE_HEIGHT_SCENE-SIZE_STATUS_BOMB-20);
    bombStatus2->setVisible(false);
    bombStatus3->setVisible(false);
    bombStatus1->setZValue(1);
    bombStatus2->setZValue(1);
    bombStatus3->setZValue(1);

    QPixmaps pointPix;
    pointPix.append(QPixmap(IMG_TEXT_POINT));
    pointPix.append(QPixmap(IMG_TEXT_POINT_1));
    pointText = new Text(SIZE_WIDTH_TEXT_POINT, SIZE_HEIGHT_TEXT_POINT, pointPix, m_scene);
    pointText->setPos(SIZE_WIDTH_SCENE-SIZE_WIDTH_TEXT_POINT-20, 20);

    QPixmaps scorePix;
    scorePix.append(QPixmap(IMG_TEXT_SCORE));
    scoreText = new Text(SIZE_WIDTH_TEXT_SCORE, SIZE_HEIGHT_TEXT_SCORE, scorePix, m_scene);
    scoreText->setPos(20, 20);

    QPixmaps bossHintPix;
    bossHintPix.append(QPixmap(IMG_TEXT_BOSSHINT));
    bossHintText = new Text(SIZE_WIDTH_TEXT_BOSSHINT, SIZE_HEIGHT_TEXT_BOSSHINT, bossHintPix, m_scene);
    bossHintText->setPos((SIZE_WIDTH_SCENE-SIZE_WIDTH_TEXT_BOSSHINT)/2, (SIZE_HEIGHT_SCENE-SIZE_HEIGHT_TEXT_BOSSHINT)/2);
    bossHintText->setVisible(false);

    scoreGame = new ScoreInGame(40, 40, m_scene);
    scoreGame->setZValue(1);
    scoreGame->setPos(10, 50);
    scoreGame->setScore(0);
}

void Space::slt_newGame()
{
    m_scene->clear();
    m_music->play();
    init();
    m_timer->start(50);
    isRunning = true;
}

void Space::slt_playerDead()
{
    m_timer->stop();
    m_music->stop();
    isRunning = false;
}

void Space::slt_startGame()
{
    if (isRunning) m_timer->start(50);
}

void Space::slt_pauseGame()
{
    m_music->pause();
    if (isRunning) m_timer->stop();
}

void Space::slt_updata()
{
    m_scene->advance();
    if(boss && m_step == textStep) {
        bossHintText->setVisible(true);
        bossHintText->deleteLater();
    }

    if(m_step == 0)
        enemys();
    m_step++;
    if (m_step % 80 == 0 && !boss) {
        enemys();
    }
    if (m_step % 233 == 0 && !boss) {
        bombsupply();
    }
    if (m_step % 666 == 0 && !boss) {
        bulletsupply();
    }
    if (m_step % 888 == 0 && !boss) {
        bloodsupply();
    }
}

void Space::slt_addscore(int score)
{
    m_scores += score;
    scoreGame->setScore(m_scores);
    scoreGame->update();
    if (score == SCORE_BOSS) {
        boss = false;
        m_level = 1;
//        m_scores = 0;
        bigFish = 1;
    }
    if(m_scores <= 50)
        m_level = 1;
    else if(m_scores < 80)
        m_level = 2;
    else if(m_scores < 200)
        m_level = 3;
    else if(m_scores < 400)
        m_level = 4;
    else if(m_scores < 600)
        m_level = 5;
//    else if(bigFish <= 0 && m_step >= 2333)
//        m_level = 7;
    else if(bigFish <= 0 && m_scores >= 800)
        m_level = 7;

}

void Space::bloodsupply()
{
    QPixmaps t;
    t.append(QPixmap(IMG_SUPPLY_BOLLD));
    BloodSupply *bloodsupply = new BloodSupply(SIZE_SUPPLY_BLOOD, SIZE_SUPPLY_BLOOD, SPEED_SUPPLY_BLOOD, t, m_scene);
    qreal x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_SUPPLY_BLOOD);
    bloodsupply->setPos(x, 0);
}

void Space::bombsupply()
{
    QPixmaps t;
    t.append(QPixmap(IMG_SUPPLY_BOMB));
    BombSupply *bombsupply = new BombSupply(SIZE_SUPPLY_BOMB, SIZE_SUPPLY_BOMB, SPEED_SUPPLY_BOMB, t, m_scene);
    qreal x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_SUPPLY_BOMB);
    bombsupply->setPos(x, 0);
}

void Space::bulletsupply()
{
    QPixmaps t;
    t.append(QPixmap(IMG_SUPPLY_BULLET));
    uint x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_SUPPLY_BULLET);
    BulletSupply *bulletsupply = new BulletSupply(SIZE_SUPPLY_BULLET, SIZE_SUPPLY_BULLET, SPEED_SUPPLY_BULLET, t, m_scene);
    bulletsupply->setPos(x,0);
}

void Space::enemys()
{
    if (m_level == 7) {
        bossHintText->setVisible(true);
        textStep = m_step + STEP_TEXTHINT;
        m_playList->setCurrentIndex(1);
        PlaneFactory::BossPlanes bossplanes = PlaneFactory::bcreator(1, scene());
        foreach (Boss *b, bossplanes) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_BOSS);
            b->setPos(x, 0);
            connect(b, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        boss = true;

    if(bigFish <= 0)
        m_level = Randomizer::creat(3, 6);

    } else if(m_level == 5) {
        PlaneFactory::FishPlanes fishplanes = PlaneFactory::fcreator(2, scene());
        foreach (Fish *f, fishplanes) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        PlaneFactory::FishPlanes fishplanes03 = PlaneFactory::fcreator_three(1, scene());
        foreach (Fish *f, fishplanes03) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH_2);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        bigFish--;
    } else if(m_level == 4) {
        PlaneFactory::FishPlanes fishplanes = PlaneFactory::fcreator(2, scene());
        foreach (Fish *f, fishplanes) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        PlaneFactory::FishPlanes fishplanes02 = PlaneFactory::fcreator_two(1, scene());
        foreach (Fish *f, fishplanes02) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH_1);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
    } else if(m_level <= 3){
        PlaneFactory::FishPlanes fishplanes = PlaneFactory::fcreator(m_level, scene());
        foreach (Fish *f, fishplanes) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
    } else {
        PlaneFactory::FishPlanes fishplanes = PlaneFactory::fcreator(1, scene());
        foreach (Fish *f, fishplanes) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
        PlaneFactory::FishPlanes fishplanes02 = PlaneFactory::fcreator_two(2, scene());
        foreach (Fish *f, fishplanes02) {
            int x = Randomizer::creat(SIZE_WIDTH_SCENE - SIZE_FISH_1);
            int y = Randomizer::creat(200);
            f->setPos(x, y-200);
            connect(f, SIGNAL(sig_score(int)), this, SLOT(slt_addscore(int)));
        }
    }
}

void Space::slt_menu()
{
    if (isRunning) {
        slt_pauseGame();
        QScopedPointer<MenuWidget> w(new MenuWidget(true, this));
        connect(w.data(), SIGNAL(sig_newGame()), this, SLOT(slt_newGame()));
        connect(w.data(), SIGNAL(sig_backStart()), this, SLOT(slt_back()));
        w->setModal(true);
        w->show();
        w->exec();
        slt_startGame();
    }
    else {
        QScopedPointer<MenuWidget> w(new MenuWidget(false, this));
        connect(w.data(), SIGNAL(sig_newGame()), this, SLOT(slt_newGame()));
        connect(w.data(), SIGNAL(sig_backStart()), this, SLOT(slt_back()));
        w->setModal(true);
        w->show();
        w->exec();
    }
}

void Space::slt_back()
{
    m_timer->stop();
    m_scene->clear();
    emit sig_showStart();
}

void Space::slt_updateBlood(int blood)
{
    switch (blood) {
    case 0:
        SIZE_STATUS_BLOOD1->setVisible(false);
        SIZE_STATUS_BLOOD2->setVisible(false);
        SIZE_STATUS_BLOOD3->setVisible(false);
        break;
    case 1:
        SIZE_STATUS_BLOOD1->setVisible(true);
        SIZE_STATUS_BLOOD2->setVisible(false);
        SIZE_STATUS_BLOOD3->setVisible(false);
        break;
    case 2:
        SIZE_STATUS_BLOOD1->setVisible(true);
        SIZE_STATUS_BLOOD2->setVisible(true);
        SIZE_STATUS_BLOOD3->setVisible(false);
        break;
    case 3:
        SIZE_STATUS_BLOOD1->setVisible(true);
        SIZE_STATUS_BLOOD2->setVisible(true);
        SIZE_STATUS_BLOOD3->setVisible(true);
        break;
    default:
        break;
    }
//    qDebug() << blood;
}

void Space::slt_updateBomb(int bomb)
{
    switch (bomb) {
    case 0:
        bombStatus1->setVisible(false);
        bombStatus2->setVisible(false);
        bombStatus3->setVisible(false);
        break;
    case 1:
        bombStatus1->setVisible(true);
        bombStatus2->setVisible(false);
        bombStatus3->setVisible(false);
        break;
    case 2:
        bombStatus1->setVisible(true);
        bombStatus2->setVisible(true);
        bombStatus3->setVisible(false);
        break;
    case 3:
        bombStatus1->setVisible(true);
        bombStatus2->setVisible(true);
        bombStatus3->setVisible(true);
        break;
    default:
        break;
    }
//    qDebug() << bomb;
}

void Space::mouseDoubleClickEvent(QMouseEvent *event) {
    event->accept();
    emit sig_menu();
}
