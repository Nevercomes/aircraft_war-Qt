QT += multimedia

CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    bloodsupply.h \
    bomb.h \
    bombsupply.h \
    boss.h \
    bullet.h \
    bulletfactory.h \
    bulletsupply.h \
    enemybullet.h \
    enemyplane.h \
    fish.h \
    flightvehicle.h \
    flyer.h \
    global.h \
    menuwidget.h \
    planefactory.h \
    playerbullet.h \
    playerPlane.h \
    randomizer.h \
    space.h \
    unflyer.h \
    supply.h \
    status.h \
    start.h \
    mybutton.h \
    text.h \
    scoreingame.h \
    logindialog.h

SOURCES += \
    bloodsupply.cpp \
    bomb.cpp \
    bombsupply.cpp \
    boss.cpp \
    bulletfactory.cpp \
    bulletsupply.cpp \
    enemybullet.cpp \
    enemyplane.cpp \
    fish.cpp \
    main.cpp \
    menuwidget.cpp \
    planefactory.cpp \
    playerbullet.cpp \
    playerPlane.cpp \
    randomizer.cpp \
    space.cpp \
    unfly.cpp \
    start.cpp \
    mybutton.cpp \
    status.cpp \
    text.cpp \
    scoreingame.cpp \
    logindialog.cpp

OTHER_FILES += \
    备注 \
    android/AndroidManifest.xml \
    android/src/org/kde/necessitas/ministro/IMinistroCallback.aidl \
    android/src/org/kde/necessitas/ministro/IMinistro.aidl \
    android/src/org/qtproject/qt5/android/bindings/QtApplication.java \
    android/src/org/qtproject/qt5/android/bindings/QtActivity.java \
    android/res/values-id/strings.xml \
    android/res/values-de/strings.xml \
    android/res/values/strings.xml \
    android/res/values/libs.xml \
    android/res/values-nb/strings.xml \
    android/res/values-el/strings.xml \
    android/res/values-zh-rCN/strings.xml \
    android/res/values-pl/strings.xml \
    android/res/values-ms/strings.xml \
    android/res/values-fr/strings.xml \
    android/res/values-ja/strings.xml \
    android/res/values-fa/strings.xml \
    android/res/layout/splash.xml \
    android/res/values-es/strings.xml \
    android/res/values-nl/strings.xml \
    android/res/values-et/strings.xml \
    android/res/values-ru/strings.xml \
    android/res/values-rs/strings.xml \
    android/res/values-ro/strings.xml \
    android/res/values-zh-rTW/strings.xml \
    android/res/values-pt-rBR/strings.xml \
    android/res/values-it/strings.xml \
    android/version.xml

RESOURCES += \
    res.qrc

FORMS += \
    logindialog.ui
