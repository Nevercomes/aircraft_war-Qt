#include "mybutton.h"

#include <QPainter>
#include <QMouseEvent>
#include <QFontMetrics>
#include <QLabel>

MyButton::MyButton(QString normal, QString hover, QString pressed, QWidget *parent) :
    QPushButton(parent)
{
    buttonState = Normal;

    normalPixmap.load(normal);
    hoverPixmap.load(hover);
    pressPixmap.load(pressed);

    this->setFixedSize(normalPixmap.size());

    this->setContentsMargins(0, 0, 0, 0);
}

MyButton::MyButton(QString IMG_BACKGROUND, QWidget *parent) :
    QPushButton(parent)
{
    buttonState = Normal;

    normalPixmap.load(IMG_BACKGROUND);
    hoverPixmap.load(IMG_BACKGROUND);
    pressPixmap.load(IMG_BACKGROUND);

    this->setFixedSize(normalPixmap.size());

    this->setContentsMargins(0, 0, 0, 0);
}

void MyButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    switch(buttonState)
    {
    case Normal:
        painter.drawPixmap(this->rect(), normalPixmap);
        break;
    case Hover:
        painter.drawPixmap(this->rect(), hoverPixmap);
        break;
    case Pressed:
        painter.drawPixmap(this->rect(), pressPixmap);
    }

    painter.drawText(this->rect(), Qt::AlignCenter, this->text());
}

void MyButton::enterEvent(QEvent *)
{
    buttonState = Hover;
    update();
}

void MyButton::leaveEvent(QEvent *)
{
    buttonState = Normal;
    update();
}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        buttonState = Pressed;
        update();
    }
}

bool isOnMyButton(const QPoint &point, const MyButton *MyButton)
{
    if(point.x() < 0 || point.x() > MyButton->width() ||
            point.y() < 0 || point.y() > MyButton->height())
    {
        return false;
    }
    return true;
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        // 判断鼠标抬起时是否在MyButton之上
        if(isOnMyButton(e->pos(), this))
        {
            emit clicked();
        }

        buttonState = Hover;
        update();
    }
}


