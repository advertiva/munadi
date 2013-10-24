#ifndef MUNADIENGINE_H
#define MUNADIENGINE_H

#include <QtGui>
#include <QtCore>
#include "libitl/prayer.h"
#include "libitl/hijri.h"
#include "settings.h"
#include <QStringList>

#if defined(Q_OS_WIN)
#include <SFML/Audio.hpp>
#else
#include <QtMultimedia/QMediaPlayer>
#endif

#define dout qDebug()

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
    QString getHijriDate();
    QString getHijriEvent();
    bool isAthanPlaying();

    Settings * settings;
    QTime testTime;

#if defined(Q_OS_WIN)
    sf::Music * athanObject;
#else
    QMediaPlayer * athanObject;
#endif


private:

    QTimer * timer;
    QString nextPrayerLabel;
    QString currentPrayerLabel;
    QString hijriEvent;

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
