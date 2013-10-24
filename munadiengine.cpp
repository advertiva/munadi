#include "munadiengine.h"
#include "settings.h"
#include "mainwindow.h"
#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioFormat>

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


//    inputFile.setFileName("app/native/res/athan.wav");
//    inputFile.open(QIODevice::ReadOnly);

//    QAudioFormat format;
//    // Set up the format, eg.
//    format.setFrequency(8000);
//    format.setChannels(1);
//    format.setSampleSize(8);
//    format.setCodec("audio/pcm");
//    format.setByteOrder(QAudioFormat::LittleEndian);
//    format.setSampleType(QAudioFormat::UnSignedInt);

//    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
//    if (!info.isFormatSupported(format)) {
//        qWarning()<<"raw audio format not supported by backend, cannot play audio.";
//        //return;
//    }

//    audio = new QAudioOutput(format, this);
//    //connect(audio,SIGNAL(stateChanged(QAudio::State)),SLOT(finishedPlaying(QAudio::State)));
//    audio->start(&inputFile);

//    qWarning() << "Suppored codec:......................" << info.supportedCodecs();


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
//#ifdef SFML
//        if(athanObject == 0) return false;

//        if(athanObject->GetStatus() == sf::Music::Playing)
//            return true;
//        else
//            return false;
//#else
    if(athanObject == 0)    return false;

    if(athanObject->state() == QMediaPlayer::PlayingState)
        return true;
    else
        return false;
//#endif

    return false;
}

void MunadiEngine::playAthan()
{ 
//#ifdef SFML
//        if(athanObject == 0)
//        {
//            QString athanFile;
//            athanFile = settings->athanPath;
//            //athanFile = QApplication::applicationDirPath();  //older code with athan file hardcoded
//            //athanFile += "/audio/athan.wav";
//            dout << "Athan file: " << athanFile;

//            athanObject = new sf::Music();
//            athanObject->OpenFromFile(athanFile.toStdString());
//        }

//        if(isAthanPlaying())
//        {
//            dout << "Athan playing, will return.";
//            return;
//        }

//        currentPrayerLabel = nextPrayerLabel;
//        athanObject->Play();
//        emit athanTriggered();
//        emit stateChanged();

//#else
        if(athanObject == 0)
        {
            //QString athanFile;
            //athanFile = settings->athanPath;
            //athanFile = QApplication::applicationDirPath();    //older code with athan file hardcoded
            //athanFile += "/audio/athan.wav";
            //dout << "Athan file: " << athanFile;
            athanObject = new QMediaPlayer();
            athanObject->setMedia(QUrl::fromLocalFile("app/native/res/athan.ogg"));
            athanObject->setVolume(100);
        }

        if(isAthanPlaying())
        {
            dout << "Athan playing, will return.";
            return;
        }

        currentPrayerLabel = nextPrayerLabel;
        athanObject->play();
        emit athanTriggered();
        emit stateChanged();

//#endif
}
void MunadiEngine::stopAthan()
{
//#ifdef SFML
//    athanObject->Stop();
//#else
    athanObject->stop();
//#endif

    emit stateChanged();
}

QString MunadiEngine::getTimeDifference()
{
    int currentMins = QTime::currentTime().hour() * 60;
    currentMins += QTime::currentTime().minute();

    QTime nextPrayerTime = getNextPrayer();

    int nextPrayerMins = nextPrayerTime.hour() * 60;
    nextPrayerMins += nextPrayerTime.minute();

    QTime time;
    time = time.addSecs(60 * (nextPrayerMins - currentMins));

    return time.toString("H 'hours' m 'minutes'");
}

QTime MunadiEngine::getNextPrayer()
{
    QTime currentTime(QTime::currentTime().hour(),QTime::currentTime().minute(), QTime::currentTime().second());

#ifdef TESTING
    if(currentTime <= getTest())
    {
        dout << "hit test";
        nextPrayerLabel = "Test";
        return getTest();
    }
    else
#endif
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
    QTime nextPrayer;
    nextPrayer = getNextPrayer();

    if(nextPrayer.isNull())    return;

    QTime currentTime(QTime::currentTime().hour(),QTime::currentTime().minute(), QTime::currentTime().second());

    if(currentTime == nextPrayer)
    {
        playAthan();
        dout << "called paly athan() ...";
    }

    if(currentTime.hour() == 0 && currentTime.minute() == 0 && currentTime.second() == 0)  //if mid-night
    {
        dout << "it is now midnight, updated prayer times..";
        calculatePrayer();
    }

    if(QTime::currentTime().second() == 0)  //every minute, update display.
    {
        emit stateChanged();
    }
}
