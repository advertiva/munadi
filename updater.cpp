#include "updater.h"
#include "globals.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QUrl>

#include <QMessageBox>

Updater::Updater(QObject *parent) :
    QObject(parent)
{
    QUrlQuery jadeedParams;
    jadeedParams.addQueryItem("lang","en");
    jadeedParams.addQueryItem("os","windows");

    QUrl jadeed("http://munadi.org/jadeed.php");
    jadeed.setQuery(jadeedParams);

    QNetworkRequest req;
    req.setUrl(jadeed);

    QNetworkAccessManager *am = new QNetworkAccessManager(this);
    connect(am, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    am->get(req);
}

void Updater::replyFinished(QNetworkReply *reply)
{
    QStringList replyStrings = QString(reply->readAll()).split(',');

    if(replyStrings.size() == 2)
    {
        QString version = replyStrings[0];
        QString details = replyStrings[1];

        if(version > APP_VERSION)
        {
            QMessageBox::information(0, tr("Munadi Update Available"), details);
        }
    }
    reply->deleteLater();
}
