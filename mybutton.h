#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>
#include <QPixmap>

typedef enum {Normal, Hover, Pressed} BUTTON_STATE;

class MyButton : public QPushButton
{
public:
    MyButton(QString normal, QString hover, QString pressed, QWidget *parent = 0);
    MyButton(QString IMG_BACKGROUND, QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    BUTTON_STATE buttonState;
    QPixmap normalPixmap, hoverPixmap, pressPixmap;
};

#endif // MYBUTTON_H
