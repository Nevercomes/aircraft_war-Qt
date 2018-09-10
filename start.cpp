#include "start.h"

#include <QPixmap>

const int START_Y = 400;
const int SPEED_X = 5;
const int PIX_WIDTH = 200;
const int PIX_HEIGHT = 80;
const int START_LEFT = -PIX_WIDTH;
const int START_RIGHT = SIZE_WIDTH_SCENE;

Start::Start(QWidget *parent) : QWidget(parent), xLeft(START_LEFT), xRight(START_RIGHT), flag(true)
{
    setWindowFlags(Qt::FramelessWindowHint);

    this->resize(SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE);

    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,
                     QBrush(QPixmap(IMG_BACKGROUND).scaled(this->size(),
                     Qt::KeepAspectRatioByExpanding,
                     Qt::SmoothTransformation)));
    this->setPalette(palette);

    label_logo = new QLabel(this);
    btn_start = new MyButton("://res/imgae/start_play2.png", "://res/imgae/start_play.png", "://res/imgae/start_play.png");
    btn_point = new MyButton("://res/imgae/start_point2.png", "://res/imgae/start_point.png", "://res/imgae/start_point.png");
    btn_score = new MyButton("://res/imgae/start_rank2.png", "://res/imgae/start_rank.png", "://res/imgae/start_rank.png");
    btn_exit  = new MyButton("://res/imgae/start_leave2.png", "://res/imgae/start_leave.png", "://res/imgae/start_leave.png");
    space = new Space;
    timer = new QTimer;
    myPlayer = new QMediaPlayer;
    loginDialog = new LoginDialog;

    btn_start->setParent(this);
    btn_point->setParent(this);
    btn_score->setParent(this);
    btn_exit->setParent(this);

//    test = new QPushButton;
//    test->setParent(this);
//    test->resize(200, 200);
//    test->setText("Test");

    connect(btn_start, SIGNAL(clicked(bool)), this, SLOT(slt_start()));
    connect(btn_point, SIGNAL(clicked(bool)), this, SLOT(slt_point()));
    connect(btn_score, SIGNAL(clicked(bool)), this, SLOT(slt_score()));
    connect(btn_exit, SIGNAL(clicked(bool)), this, SLOT(slt_exit()));

    connect(space, SIGNAL(sig_showStart()), this, SLOT(slt_startShow()));



    initLayout();
    init();

    timer->setInterval(50);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(slt_onTimeOut()));
}

Start::~Start()
{

}

void Start::initLayout()
{

    label_logo->setGeometry(20, 200, 100, 100);
    int width = btn_start->width();
    int height = btn_start->height();
    int x = (this->width()-width) / 2 - 5;

    btn_start->setGeometry(x, 500, width, height);
    btn_point->setGeometry(x, 560, width, height);
    btn_score->setGeometry(x, 620, width, height);
    btn_exit->setGeometry(x, 680, width, height);


//    test->setGeometry(x, 300, width, height);

//    QVBoxLayout *mainLayout = new QVBoxLayout(this);
//    mainLayout->addStretch();

//    mainLayout->addWidget(btn_start);
//    mainLayout->addWidget(btn_point);
//    mainLayout->addWidget(btn_score);
//    mainLayout->addWidget(btn_exit);

//    this->setLayout(mainLayout);
}

void Start::init()
{
    QPixmap logoPix;
    logoPix.load(IMG_START_LOGO);
    label_logo->resize(logoPix.size());
    label_logo->setPixmap(logoPix);

    leftPix.load(IMG_START_PLANE_LEFT);
    rightPix.load(IMG_START_PLANE_RIGHT);

    playList = new QMediaPlaylist;
    playList->addMedia(QUrl(SOUND_START_BG));
    playList->setCurrentIndex(0);
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    myPlayer->setPlaylist(playList);
    myPlayer->play();

    loginDialog->setWindowFlags(Qt::FramelessWindowHint);
//    loginDialog->exec();
//    loginDialog->show();
//    this->setAttribute(Qt::WA_ShowWithoutActivating,true);
//    loginDialog->setFocus();
}

void Start::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(flag)
        painter.drawPixmap(xLeft, START_Y, leftPix);
    else
        painter.drawPixmap(xRight, START_Y, rightPix);
}

void Start::slt_start()
{
    myPlayer->stop();
    space->resize(SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE);
    space->show();
    this->hide();
}

void Start::slt_point()
{

}

void Start::slt_score()
{

}

void Start::slt_exit()
{
    this->close();
}

void Start::slt_startShow()
{
//    timer->stop();
    space->hide();
    this->show();
}

void Start::slt_onTimeOut()
{
    if(flag){
        if(xLeft >= SIZE_WIDTH_SCENE + PIX_WIDTH){
            xLeft = START_LEFT;
            flag = false;
        }
        else{
            xLeft += SPEED_X;
        }
    }
    else{
        if(xRight <= 0 - PIX_WIDTH - 30){ // 图片补偿
            xRight = START_RIGHT;
            flag = true;
        }
        else{
            xRight -= SPEED_X;
        }
    }
    update();
}
