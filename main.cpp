#include <QApplication>

#include "start.h"
#include "space.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    Start gameSatrt;
    gameSatrt.show();
//    Space space;
//    space.resize(SIZE_WIDTH_SCENE, SIZE_HEIGHT_SCENE);
//    space.move(QApplication::desktop()->rect().center() - QPoint(SIZE_WIDTH_SCENE/2, SIZE_HEIGHT_SCENE/2));
//    space.show();

    return app.exec();
}
