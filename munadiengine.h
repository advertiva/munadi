#ifndef MUNADIENGINE_H
#define MUNADIENGINE_H

//#define TESTING //Just for testing

#include <QtGui>
#include <QtCore>
//#include <QtNetwork>
#include "libitl/prayer.h"
#include "settings.h"
#include <QStringList>

#ifdef SFML
//#include <SFML/Audio.hpp>
#else
#include <QtMultimediaKit/QMediaPlayer>
#endif

#include <QtMultimedia/QAudioOutput>
#include <QFile>


#define dout qDebug()

class QMediaPlayer;

class MunadiEngine : public QObject
{
    Q_OBJECT

public:

    MunadiEngine(QObject * parent = 0);
    virtual ~MunadiEngine();

    enum PrayerType{Fajr, Sunrise, Duhr, Asr, Magrib, Isha};

    QTime getFajr();
    QTime getDuhr();
    QTime getAsr();
    QTime getMagrib();
    QTime getIsha();
    QTime getTest();
    QTime getSunrise();
    QString getTimeDifference();
    QTime getNextPrayer();
    QString getNextPrayerLabel();
    QString getCurrPrayerLabel();
    bool isAthanPlaying();
    void update() { emit stateChanged(); }

    Settings * settings;
    QTime testTime;

//#ifdef SFML
//    sf::Music * athanObject;
//#else
    QMediaPlayer * athanObject;
//#endif

private:

    QTimer * timer;
    QString nextPrayerLabel;
    QString currentPrayerLabel;

//    QFile inputFile;     // class member.
//    QAudioOutput* audio; // class member.

public slots:
    void playAthan();
    void stopAthan();
    void checkAthan();
    void calculatePrayer();
    void calculateAngle();

signals:
    void athanTriggered();
    void stateChanged();

};

#endif // MUNADIENGINE_H
