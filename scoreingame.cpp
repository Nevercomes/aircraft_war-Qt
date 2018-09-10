#include "scoreingame.h"

#include <QString>

ScoreInGame::ScoreInGame(qreal w, qreal h, QGraphicsScene *scene, QGraphicsItem *parent)
    : UnFlyer(parent), m_w(w), m_h(h), score(0)
{
    // Font...
    font.setFamily("Microsoft YaHei");
    // 大小
    font.setPointSize(24);
    // 斜体
//    font.setItalic(true);
    // 设置字符间距
//    font.setLetterSpacing(QFont::AbsoluteSpacing, 20);
    scene->addItem(this);
}

ScoreInGame::~ScoreInGame()
{

}

void ScoreInGame::setScore(int score)
{
    this->score = score;
}

QRectF ScoreInGame::boundingRect() const
{
    QPointF pos = scenePos();
    QRectF rect(pos.rx(), pos.ry(), m_w, m_h);
    return rect;
}

QPainterPath ScoreInGame::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void ScoreInGame::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QColor(0, 0, 0, 80));
    // 使用字体
    painter->setFont(font);

    QString str_score = QString::number(score, 10);
    QPointF pos = scenePos();
    painter->drawText(pos, str_score);
}

void ScoreInGame::advance(int)
{
    QPointF pos = scenePos();
    setPos(pos);
}
