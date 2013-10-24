# -------------------------------------------------
# Project created by QtCreator 2009-05-20T18:31:05
# -------------------------------------------------

#QMAKE_LFLAGS += '-Wl,-rpath,\'./app/native/lib\''

DEFINES += QT_NO_DEBUG_OUTPUT
DEFINES -= TESTING
DEFINES -= TESTING0


#QT +=   network \
#        multimedia

CONFIG += mobility
MOBILITY += multimedia


#QT += network
#CONFIG += qt debug
#INCLUDEPATH += ../Qt/include
#LIBS += C:\SFML\lib\ -lsfml-audio -lsfml-system

SOURCES +=
HEADERS +=
FORMS +=



TARGET =    munadi
TEMPLATE =  app

SOURCES +=  main.cpp \
            mainwindow.cpp \
            munadiengine.cpp \
            settingsdialog.cpp \
            libitl/umm_alqura.c \
            libitl/prayer.c \
            libitl/hijri.c \
            libitl/astro.c

HEADERS +=  mainwindow.h \
            munadiengine.h \
            settingsdialog.h \
            libitl/prayer.h \
            libitl/hijri.h \
            libitl/astro.h \
            settings.h \
            globals.h

FORMS +=    settingsdialog.ui \
            mainwindow.ui

#OTHER_FILES +=   \
#                desktop/munadi.desktop \
#                desktop/munadi.png \
#                desktop/org.indt.munadi.service
#RESOURCES += resources.qrc

#QMAKE_LFLAGS += '-Wl,-rpath,\'./app/native/lib\''

package.target = $${TARGET}.bar
package.depends = $$TARGET
package.commands = blackberry-nativepackager \
   #-devMode \
   #-debugToken ./debugTokenMob.bar \
   -package $${TARGET}.bar blackberry-tablet.xml $$TARGET \
   -e res/athan.ogg res/athan.ogg \
   -e res/icon.png res/icon.png \
   -e res/play.png res/play.png \
   -e res/stop.png res/stop.png \
   #-e res/splashscreen.png res/splashscreen.png \
   -e res/BB10.png res/BB10.png \
   -e res/Purisa.ttf res/Purisa.ttf \
   -e res/countries.tsv res/countries.tsv \
   -e res/cities.tsv res/cities.tsv

QMAKE_EXTRA_TARGETS += package
