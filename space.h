#ifndef SPACE_H
#define SPACE_H

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "planefactory.h"
#include "playerPlane.h"
#include "bloodsupply.h"
#include "bombsupply.h"
#include "bulletsupply.h"
#include "randomizer.h"
#include "menuwidget.h"
#include "status.h"
#include "text.h"
#include "scoreingame.h"

class Space : public QGraphicsView
{
    Q_OBJECT
public:
    Space(QWidget *parent = 0);
    void init();
    void bloodsupply();
    void bombsupply();
    void bulletsupply();
    void enemys();

protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void sig_menu();
    void sig_showStart();
    void sig_updateScore(int score);

protected slots:
    void slt_newGame();
    void slt_playerDead();
    void slt_startGame();
    void slt_pauseGame();
    void slt_updata();
    void slt_addscore(int);
    void slt_menu();
    void slt_back();

    void slt_updateBlood(int blood);
    void slt_updateBomb(int bomb);

private:
//    QGraphicsTextItem *scoretext, *bloodtext, *bombtext;
    QGraphicsScene *m_scene;
    QTimer *m_timer;

    bool boss;
    bool isRunning;
    bool isWaiting;
    PlayerPlane *m_player;

    Status *SIZE_STATUS_BLOOD1, *SIZE_STATUS_BLOOD2, *SIZE_STATUS_BLOOD3;
    Status *bombStatus1, *bombStatus2, *bombStatus3;
    Text *pointText, *scoreText, *bossHintText;
//    QGraphicsTextItem *scoreItem;
    ScoreInGame *scoreGame;

    QMediaPlaylist *m_playList;
    QMediaPlayer *m_music;

    uint m_scores, m_bloods, m_bombs, m_level, m_round, m_step;
    uint bigFish;

    uint textStep;

};

#endif // SPACE_H
