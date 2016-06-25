#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T08:56:02
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shootergame
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    object.cpp \
    player.cpp \
    gun.cpp \
    bullet.cpp \
    score.cpp \
    status.cpp \
    walker.cpp \
    enemy.cpp \
    walking.cpp \
    shooting.cpp \
    shooter.cpp \
    enemybullet.cpp \
    pbullet.cpp \
    tower1.cpp \
    tower2.cpp \
    bullet_tower.cpp \
    tower.cpp \
    tower3.cpp \
    button.cpp

HEADERS  += \
    game.h \
    object.h \
    player.h \
    gun.h \
    bullet.h \
    score.h \
    status.h \
    walker.h \
    enemy.h \
    walking.h \
    shooting.h \
    shooter.h \
    enemybullet.h \
    pbullet.h \
    tower1.h \
    tower2.h \
    bullet_tower.h \
    tower.h \
    tower3.h \
    button.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc \
    music.qrc
