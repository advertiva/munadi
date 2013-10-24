# -------------------------------------------------
# Project created by QtCreator 2009-05-20T18:31:05
# -------------------------------------------------

DEFINES -= QT_NO_DEBUG_OUTPUT

unix:!symbian {

    maemo5 {

        QT += network
        CONFIG += mobility qdbus
        MOBILITY += multimedia

        SOURCES += maemo_mainwindow.cpp
        HEADERS += maemo_mainwindow.h
        FORMS += maemo_mainwindow.ui

        target.path = /opt/munadi

        icon.path = /usr/share/icons
        icon.files = desktop/munadi.png

        audio.path = /opt/munadi/audio
        audio.files = audio/athan.wav

        desktop.path = /usr/share/applications/hildon
        desktop.files = desktop/munadi.desktop

        service.path = /usr/share/dbus-1/services
        service.files = desktop/org.indt.munadi.service

        INSTALLS += target audio service icon desktop

    } else {

        QT += core gui widgets multimedia
        CONFIG += qt
        INCLUDEPATH += /usr/include

        target.path = /usr/local/bin

        SOURCES += mainwindow.cpp
        HEADERS += mainwindow.h
        FORMS += mainwindow.ui
    }
}

symbian{

}

win32 {

DEFINES += SFML_STATIC

QT += core gui widgets network
CONFIG += qt
#INCLUDEPATH += D:/CppLibs/SFML-MinGW-2.0-rc/include
INCLUDEPATH +=B:/dev/CppLibs/SFML-MinGW-1.6/include
debug {
#LIBS += D:/CppLibs/SFML-MinGW-2.0-rc/lib/libsfml-audio-s-d.a \
#        D:/CppLibs/SFML-MinGW-2.0-rc/lib/libsfml-system-s-d.a \
#        D:/CppLibs/SFML-MinGW-2.0-rc/lib/libsfml-main-d.a

LIBS += B:/dev/CppLibs/SFML-MinGW-1.6/lib/libsfml-audio-s-d.a \
        B:/dev/CppLibs/SFML-MinGW-1.6/lib/libsfml-system-s-d.a
}
release {
#LIBS += D:/CppLibs/SFML-MinGW-2.0-rc/lib/libsfml-audio-s.a D:/CppLibs/SFML-MinGW-2.0-rc/lib/libsfml-system-s.a
LIBS += B:/dev/CppLibs/SFML-MinGW-1.6/lib/libsfml-audio-s.a \
        B:/dev/CppLibs/SFML-MinGW-1.6/lib/libsfml-system-s.a
}

SOURCES += mainwindow.cpp
HEADERS += mainwindow.h
FORMS += mainwindow.ui

}

TARGET = munadi
TEMPLATE = app

SOURCES +=  main.cpp \
            munadiengine.cpp \
            settingsdialog.cpp \
            libitl/umm_alqura.c \
            libitl/prayer.c \
            libitl/hijri.c \
            libitl/astro.c \
    updater.cpp

HEADERS +=  munadiengine.h \
            settingsdialog.h \
            libitl/prayer.h \
            libitl/hijri.h \
            libitl/astro.h \
            settings.h \
            globals.h \
    updater.h

FORMS += settingsdialog.ui

RESOURCES += resources.qrc

OTHER_FILES +=  audio/athan.wav \
                desktop/munadi.desktop \
                desktop/munadi.png \
                desktop/org.indt.munadi.service


