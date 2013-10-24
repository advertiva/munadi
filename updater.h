#ifndef UPDATER_H
#define UPDATER_H

#include <QObject>

class Updater : public QObject
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    
signals:
    
public slots:
    void replyFinished(class QNetworkReply *reply);
    
};

#endif // UPDATER_H
