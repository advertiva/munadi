#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QtGui/QDialog>
#include "munadiengine.h"
#include "globals.h"
#define WEBSERVICE_URL "http://tinygeocoder.com/create-api.php?q="

struct City;

namespace Ui {
    class settingsDialog;
}

class settingsDialog : public QDialog {
    Q_OBJECT
public:
    settingsDialog(MunadiEngine * munadiEngine, QWidget *parent = 0);
    ~settingsDialog();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::settingsDialog *m_ui;
    MunadiEngine * munadi;
    QNetworkAccessManager * netManager;
    QString locationInput;
    City foundCity;

    void autoDetectLocation();
    void displayResults(City & city);
    City parseIPLocTools(QByteArray &);

    void syncSettings();

private slots:
    void on_pbTestAthan_clicked();
    void on_pbChangePath_clicked();
    void on_btnProbeWS_clicked();
    void netReplyReceived(QNetworkReply *);
    void on_bbAthanOptions_accepted();
    void on_bbCalcMethods_accepted();
    void on_bbLocation_accepted();
    void on_bbLocation_rejected();
    void on_bbCalcMethods_rejected();
    void on_bbAthanOptions_rejected();
};

#endif // SETTINGSDIALOG_H
