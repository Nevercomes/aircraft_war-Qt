#include "menuwidget.h"

MenuWidget::MenuWidget(bool isRunning, QWidget *parent) : QDialog(parent), states(isRunning) {
    setWindowFlags(Qt::FramelessWindowHint);
    initUI();
    setMinimumSize(150,300);
    setMaximumSize(150,300);
    move(parent->rect().center() - QPoint(150/2,300/2));
    connect(m_new, SIGNAL(clicked()), this, SLOT(slt_newGame()));
    connect(m_quit, SIGNAL(clicked()), this ,SLOT(slt_backStart()));
    connect(m_back, SIGNAL(clicked()), this, SLOT(close()));
}

void MenuWidget::initUI()
{
    m_new = new QPushButton("New Game");
    m_back = new QPushButton("Back Game");
    m_quit = new QPushButton("Main Menu");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addWidget(m_new);
    mainLayout->addWidget(m_back);
    mainLayout->addWidget(m_quit);
    mainLayout->addStretch();
    setLayout(mainLayout);

    if (states) {
        m_new->setDisabled(false);

    } else {
        m_back->setDisabled(true);
    }
}

void MenuWidget::slt_backStart()
{
    emit sig_backStart();
    close();
}

void MenuWidget::slt_newGame()
{
    emit sig_newGame();
    close();
}
