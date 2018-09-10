#include "randomizer.h"

Randomizer::Randomizer(QObject *parent) : QObject(parent) {}

int Randomizer::creat(int x)
{
    return qrand() % x;
}

int Randomizer::creat(int x, int y)
{
    return qrand() % (y - x) + x;
}
