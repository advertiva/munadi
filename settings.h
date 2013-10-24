#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets/QApplication>
#include "globals.h"

class Settings
{
public: //TODO: change to private

    QSettings qSettings;
    QRect screenGeo;
    QRect settingScreenGeo;
    City currentCity;
    double qiblaAngle;
    QString athanPath;
    bool showOnAthan;
    bool checkForUpdates;
    bool compactMode;
    bool farjEnabled, duhrEnabled, asrEnabled, magribEnabled, ishaEnabled;
    int farjAdjustment, duhrAdjustment, asrAdjustment, magribAdjustment, ishaAdjustment;

public:

    Settings()
        : showOnAthan(true),
          checkForUpdates(true),
          compactMode(false),
          farjEnabled(true),
          duhrEnabled(true),
          asrEnabled(true),
          magribEnabled(true),
          ishaEnabled(true),
          qiblaAngle(0.0),
          farjAdjustment(0),
          duhrAdjustment(0),
          asrAdjustment(0),
          magribAdjustment(0),
          ishaAdjustment(0)
    {
        showOnAthan = qSettings.value("mainwindow/showOnAthan", true).toBool();
        checkForUpdates = qSettings.value("mainwindow/checkForUpdates", true).toBool();
        compactMode = qSettings.value("mainwindow/compactMode", false).toBool();
        screenGeo = qSettings.value("mainwindow/geometry",QRect(400,300,550,350)).toRect();
        settingScreenGeo = qSettings.value("settingdialog/geometry", QRect(400,300,550,400)).toRect();

        farjEnabled = qSettings.value("athan/farjEnabled", true).toBool();
        duhrEnabled = qSettings.value("athan/duhrEnabled", true).toBool();
        asrEnabled = qSettings.value("athan/asrEnabled", true).toBool();
        magribEnabled = qSettings.value("athan/magribEnabled", true).toBool();
        ishaEnabled = qSettings.value("athan/ishaEnabled", true).toBool();

        farjAdjustment = qSettings.value("athan/farjAdjustment").toInt();
        duhrAdjustment = qSettings.value("athan/duhrAdjustment").toInt();
        asrAdjustment = qSettings.value("athan/asrAdjustment").toInt();
        magribAdjustment = qSettings.value("athan/magribAdjustment").toInt();
        ishaAdjustment = qSettings.value("athan/ishaAdjustment").toInt();

        if((qSettings.value("location/latitude").toString() == "" && qSettings.value("location/longitude").toString() == "") ||
           (qSettings.value("location/latitude").toString() == "0" && qSettings.value("location/longitude").toString() == "0"))//If no location set in config file, use default (Mecca).
        {
           setCity("Mecca, Saudi Arabia", 21.429729, 39.828369, 3.0, 0, 1, 4);
           qiblaAngle = 0;
        }
        else
        {
            //Set city
            setCity(
            qSettings.value("location/name").toString(),
            qSettings.value("location/latitude").toDouble(),
            qSettings.value("location/longitude").toDouble(),
            qSettings.value("location/gmtDiff").toDouble(),
            qSettings.value("location/dst").toInt(),
            qSettings.value("method/mathhab").toInt(),
            qSettings.value("method/calcMethod").toInt()
            );
            qiblaAngle = qSettings.value("location/qibla").toDouble();
        }

#ifdef Q_OS_WIN
        athanPath = QApplication::applicationDirPath() + "/audio/athan.ogg";
#else
        athanPath = QApplication::applicationDirPath() + "/audio/athan.ogg";
#endif

        /*if (qSettings.value("athan/normalPath").toString() == "")
        {
            athanPath = QApplication::applicationDirPath() + "/audio/athan.ogg";
        }
        else
        {
            //athanPath = qSettings.value("athan/normalPath").toString(); TODO: Remove below
            athanPath = QApplication::applicationDirPath() + "/audio/athan.ogg";
        }*/
    }

    ~Settings()
    {
        qSettings.setValue("mainwindow/showOnAthan", showOnAthan);
        qSettings.setValue("mainwindow/checkForUpdates", checkForUpdates);
        qSettings.setValue("mainwindow/compactMode", compactMode);
        qSettings.setValue("mainwindow/geometry", screenGeo);

        qSettings.setValue("settingdialog/geometry", settingScreenGeo);

        qSettings.setValue("location/name", currentCity.name);
        qSettings.setValue("location/latitude", currentCity.location.degreeLat);
        qSettings.setValue("location/longitude", currentCity.location.degreeLong);
        qSettings.setValue("location/gmtDiff", currentCity.location.gmtDiff);
        qSettings.setValue("location/dst", currentCity.location.dst);
        qSettings.setValue("location/qibla",qiblaAngle);

        qSettings.setValue("method/mathhab", currentCity.method.mathhab);
        qSettings.setValue("method/calcMethod", currentCity.calcMethod);

        qSettings.setValue("athan/normalPath", athanPath);

        qSettings.setValue("athan/farjEnabled", farjEnabled);
        qSettings.setValue("athan/duhrEnabled", duhrEnabled);
        qSettings.setValue("athan/asrEnabled", asrEnabled);
        qSettings.setValue("athan/magribEnabled", magribEnabled);
        qSettings.setValue("athan/ishaEnabled", ishaEnabled);

        qSettings.setValue("athan/farjAdjustment", farjAdjustment);
        qSettings.setValue("athan/duhrAdjustment", duhrAdjustment);
        qSettings.setValue("athan/asrAdjustment", asrAdjustment);
        qSettings.setValue("athan/magribAdjustment", magribAdjustment);
        qSettings.setValue("athan/ishaAdjustment", ishaAdjustment);

        qSettings.sync();
    }

    void setCity(QString name, double latitude, double longitude, double gmtDiff, int dst, int mathhab, int calcMethod)
    {
        //Location
        currentCity.name = name;
        currentCity.location.degreeLat = latitude;
        currentCity.location.degreeLong = longitude;
        currentCity.location.gmtDiff = gmtDiff;
        currentCity.location.dst = dst;
        currentCity.calcMethod = calcMethod;
        getMethod(currentCity.calcMethod, &currentCity.method);
        currentCity.method.mathhab = mathhab;

        //... defaults
        currentCity.location.pressure = 1010;
        currentCity.location.seaLevel = 0;
        currentCity.location.temperature = 10;
        currentCity.method.round = 3;   //Better rounding for imsaak, agressive
    }

    City getCity()
    {
        return currentCity;
    }
};

#endif // SETTINGS_H
