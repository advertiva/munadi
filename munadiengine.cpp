#include "munadiengine.h"
#include "settings.h"
#include "mainwindow.h"
#include <QtWidgets/QMessageBox>
#include <QTime>

MunadiEngine::MunadiEngine(QObject * parent)
    : QObject(parent)
    , athanObject(0)
    , settings(new Settings())
    , timer(new QTimer(this))
{
    calculatePrayer();
    getNextPrayer();

    timer->setInterval(1000);
    timer->start();

    connect(timer, SIGNAL(timeout()), this, SLOT(checkAthan()));
}
MunadiEngine::~MunadiEngine()
{
    if(athanObject) delete athanObject;
    if(settings)    delete settings;
}
void MunadiEngine::calculatePrayer()
{
    Date date;  // Different from QDate
    date.day = QDate::currentDate().day();
    date.month = QDate::currentDate().month();
    date.year = QDate::currentDate().year();

    getPrayerTimes(&settings->currentCity.location,
                   &settings->currentCity.method,
                   &date,
                   settings->currentCity.ptList);

    getNextPrayer();    //Fix bug with mainwindow refresh with wrong details.
    emit stateChanged();
}

void MunadiEngine::calculateAngle()
{
    settings->qiblaAngle = getNorthQibla(&settings->currentCity.location);
}

QTime MunadiEngine::getFajr()
{
    return QTime(settings->currentCity.ptList[Fajr].hour,
                 settings->currentCity.ptList[Fajr].minute).addSecs(settings->farjAdjustment * 60);
}
QTime MunadiEngine::getDuhr()
{
    return QTime(settings->currentCity.ptList[Duhr].hour,
                 settings->currentCity.ptList[Duhr].minute).addSecs(settings->duhrAdjustment * 60);
}
QTime MunadiEngine::getAsr()
{
    return QTime(settings->currentCity.ptList[Asr].hour,
                 settings->currentCity.ptList[Asr].minute).addSecs(settings->asrAdjustment * 60);
}
QTime MunadiEngine::getMagrib()
{
    return QTime(settings->currentCity.ptList[Magrib].hour,
                 settings->currentCity.ptList[Magrib].minute).addSecs(settings->magribAdjustment * 60);
}
QTime MunadiEngine::getIsha()
{
    return QTime(settings->currentCity.ptList[Isha].hour,
                 settings->currentCity.ptList[Isha].minute).addSecs(settings->ishaAdjustment * 60);
}
QTime MunadiEngine::getTest()
{
    return testTime;
}
QTime MunadiEngine::getSunrise()
{
    return QTime(settings->currentCity.ptList[Sunrise].hour,
                 settings->currentCity.ptList[Sunrise].minute);
}

bool MunadiEngine::isAthanPlaying()
{
    if(athanObject == 0)    return false;

#if defined(Q_OS_WIN) || defined(Q_OS_UNIXz)
    if(athanObject->GetStatus() == sf::Music::Playing)
        return true;
#else
    if(athanObject->state() == QMediaPlayer::PlayingState)
        return true;
#endif

    return false;
}

void MunadiEngine::playAthan()
{ 
    if(athanObject == 0)
    {
        QString athanFile;
        athanFile = settings->athanPath;
        //athanFile = QApplication::applicationDirPath();    //older code with athan file hardcoded
        //athanFile += "/audio/athan.wav";
        dout << "Athan file: " << athanFile;

#if defined(Q_OS_WIN)
        athanObject = new sf::Music();
        if(!athanObject->OpenFromFile(athanFile.toStdString()))
        {
            QMessageBox::critical(0, tr("Athan File"), tr("Unable to play Athan file."));
        }
        //athanObject->SetVolume(1.0f);
#else
        athanObject = new QMediaPlayer();
        athanObject->setMedia(QUrl::fromLocalFile((athanFile)));
        athanObject->setVolume(100);
#endif

    }

    if(isAthanPlaying())
    {
        dout << "Athan playing, will return.";
        return;
    }

    currentPrayerLabel = nextPrayerLabel;
#if defined(Q_OS_WIN)
    athanObject->Play();
#else
    athanObject->play();
#endif
    emit athanTriggered();
    emit stateChanged();
}
void MunadiEngine::stopAthan()
{
#if defined(Q_OS_WIN)
    athanObject->Stop();
#else
    athanObject->stop();
#endif
    emit stateChanged();
}

QString MunadiEngine::getTimeDifference()
{
    int currentMins = QTime::currentTime().hour() * 60;
    currentMins += QTime::currentTime().minute();

    QTime nextPrayerTime = getNextPrayer();

    int nextPrayerMins = nextPrayerTime.hour() * 60;
    nextPrayerMins += nextPrayerTime.minute();

    //Below is funny, it is there to avoid compiler optimising it out!!!
    long t = 60 * (nextPrayerMins - currentMins);
    QTime *tm = new QTime(0,0,0,0);
    QString time = (tm->addSecs(t)).toString("H 'hours' m 'minutes'");
    delete tm;

    qDebug() << "Time difference: " << time;

    return time;

    /*QTime time;
    time = time.addSecs(60 * (nextPrayerMins - currentMins));

    return time.toString("H 'hours' m 'minutes'");*/
}

QTime MunadiEngine::getNextPrayer()
{
    QTime currentTime(QTime::currentTime().hour(),QTime::currentTime().minute(), QTime::currentTime().second());

    if(currentTime <= getFajr() && settings->farjEnabled)
    {
        dout<< "HIT FAJR";

        nextPrayerLabel = "Fajr";
        return getFajr();
    }
    else if(currentTime <= getDuhr() && settings->duhrEnabled)
    {
        dout<< "HIT THUHR";

        nextPrayerLabel = "Duhr";
        return getDuhr();
    }
    else if(currentTime <= getAsr() && settings->asrEnabled)
    {
        dout<< "HIT ASR";

        nextPrayerLabel = "Asr";
        return getAsr();
    }
    else if(currentTime <= getMagrib() && settings->magribEnabled)
    {
        dout<< "HIT MAGHRIB";

        nextPrayerLabel = "Magrib";
        return getMagrib();
    }
    else if(currentTime <= getIsha() && settings->ishaEnabled)
    {
        dout<< "HIT ISHA";

        nextPrayerLabel = "Isha";
        return getIsha();
    }
    else if(settings->farjEnabled)  // This is need again, hard to explain why!!!
    {
        dout<< "HIT FAJR L";

        nextPrayerLabel = "Fajr";
        return getFajr();
    }
    else    // rotated back
    {
        dout<< "NONE";

        nextPrayerLabel = "none";
        return QTime();
    }
}

QString MunadiEngine::getNextPrayerLabel()
{
    return nextPrayerLabel;
}

QString MunadiEngine::getCurrPrayerLabel()
{
    return currentPrayerLabel;
}

void MunadiEngine::checkAthan()
{
    dout << "checkAthan() called";

    calculatePrayer();

    QTime nextPrayer = getNextPrayer();

    if(nextPrayer.isNull())    return;

    QTime currentTime(QTime::currentTime().hour(),QTime::currentTime().minute(), QTime::currentTime().second());

    if(currentTime == nextPrayer)
    {
        playAthan();
        dout << "called paly athan() ...";
    }
}

QString MunadiEngine::getHijriDate()
{
    sDate hDate;

    // Convert using hijri code from meladi to hijri
    int ret = h_date(&hDate,
                     QDate::currentDate().day(),
                     QDate::currentDate().month(),
                     QDate::currentDate().year());

    if (ret)
        return "";

    QString hijriDate;
    hijriDate = hijriDate.append(QString::number(hDate.day));   // Date number
    hijriDate = hijriDate.append(" ");   // Date name
    hijriDate = hijriDate.append(hDate.to_mname);   // Date name
    hijriDate = hijriDate.append(", ");   // Date name
    hijriDate = hijriDate.append(QString::number(hDate.year));   // Date name

    hijriEvent = "";

    for (int i = 0; hDate.event[i] != NULL; i++)
    {
       //printf("  Day's Event      - %s\n", mydate.event[i]);

        hijriEvent.append(hDate.event[i]);
    }
    free(hDate.event);

    return hijriDate;
}

QString MunadiEngine::getHijriEvent()
{
    if(hijriEvent == "")
        return "Subhan Allah, Alhamdulliah, Allahuakbar";
    else
        return hijriEvent;
}
