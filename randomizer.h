#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <QObject>

class Randomizer : public QObject
{
    Q_OBJECT
public:
    static int creat(int x);
    static int creat(int x, int y);
private:
    explicit Randomizer(QObject *parent = 0);
};

#endif // RANDOMIZER_H
