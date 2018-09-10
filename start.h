#ifndef START_H
#define START_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

#include "global.h"
#include "mybutton.h"
#include "space.h"
#include "logindialog.h"

class Start : public QWidget
{
    Q_OBJECT
public:
    explicit Start(QWidget *parent = 0);
    ~Start();
    void initLayout();
    void init();

    void paintEvent(QPaintEvent *event);

private:
    QLabel *label_logo;

    MyButton *btn_start;
    MyButton *btn_point;
    MyButton *btn_score;
    MyButton *btn_exit;

    QTimer *timer;
    QPixmap leftPix, rightPix;
    int xLeft, xRight;
    bool flag;

//    QPushButton *test;

    QMediaPlaylist *playList;
    QMediaPlayer *myPlayer;
    Space *space;
    LoginDialog *loginDialog;

signals:

public slots:
    void slt_start();
    void slt_point();
    void slt_score();
    void slt_exit();

    void slt_startShow();
    void slt_onTimeOut();

};

#endif // START_H
