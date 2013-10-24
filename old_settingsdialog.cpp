#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "settings.h"
#include <QFileDialog>

settingsDialog::settingsDialog(MunadiEngine * munadiEngine, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::settingsDialog)
{
    m_ui->setupUi(this);
#ifdef Q_WS_MAEMO_5
    this->setGeometry(this->x(), this->y(), this->width(), 480);
#endif

    munadi = munadiEngine;
    netManager = new QNetworkAccessManager(this);
    connect(netManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(netReplyReceived(QNetworkReply*)));

    m_ui->progressBar->setVisible(false);

    // Method tab
    m_ui->cbMathhab->setCurrentIndex(munadi->settings->currentCity.method.mathhab-1);          // show existing
    m_ui->cbMethod->setCurrentIndex(munadi->settings->currentCity.calcMethod-1);               // settings to the user

    // Location tab
    m_ui->cbDaylightSaving->setChecked(munadi->settings->currentCity.location.dst);
    m_ui->tbLatitude->setText(QString::number(munadi->settings->currentCity.location.degreeLat));
    m_ui->tbLongitude->setText(QString::number(munadi->settings->currentCity.location.degreeLong));
    m_ui->sbGmtOffset->setValue(munadi->settings->currentCity.location.gmtDiff);
    m_ui->tbLocationAddress->setText(munadi->settings->currentCity.name);

    // Athan tab
    m_ui->tbAthanPath->setText(munadi->settings->athanPath);
    m_ui->cbFajrEnabled->setChecked(munadi->settings->farjEnabled);
    m_ui->cbDuhrEnabled->setChecked(munadi->settings->duhrEnabled);
    m_ui->cbAsrEnabled->setChecked(munadi->settings->asrEnabled);
    m_ui->cbMagribEnabled->setChecked(munadi->settings->magribEnabled);
    m_ui->cbIshaEnabled->setChecked(munadi->settings->ishaEnabled);

    m_ui->sbFajrAdjustment->setValue(munadi->settings->farjAdjustment);
    m_ui->sbDuhrAdjustment->setValue(munadi->settings->duhrAdjustment);
    m_ui->sbAsrAdjustment->setValue(munadi->settings->asrAdjustment);
    m_ui->sbMagribAdjustment->setValue(munadi->settings->magribAdjustment);
    m_ui->sbIshaAdjustment->setValue(munadi->settings->ishaAdjustment);
}

settingsDialog::~settingsDialog()
{
    delete m_ui;
}

void settingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void settingsDialog::on_btnProbeWS_clicked()
{
    m_ui->progressBar->setVisible(true);

    QString query = WEBSERVICE_URL + m_ui->tbLocationAddress->text();
    netManager->get(QNetworkRequest(QUrl(query)));
}
void settingsDialog::netReplyReceived(QNetworkReply * reply)
{
    QByteArray data(reply->readAll());
    if(data.size() == 0 || !isdigit(data[0]))
    {
        QMessageBox::information(this, "Location not found", "The address appears to be invalid or not found.\n"
                                 "Please enter details manually.");
        return;
    }
    foundCity = parseIPLocTools(data);
    displayResults(foundCity);
}
City settingsDialog::parseIPLocTools(QByteArray & data)
{
    QList<QByteArray> results = data.split(',');
    City city;

    city.name = m_ui->tbLocationAddress->text();
    city.location.degreeLat = results[0].toDouble();
    city.location.degreeLong = results[1].toDouble();

    return city;
}
void settingsDialog::displayResults(City & city)
{
    m_ui->progressBar->setVisible(false);

    m_ui->tbLatitude->setText(QString::number(city.location.degreeLat));
    m_ui->tbLongitude->setText(QString::number(city.location.degreeLong));
}

void settingsDialog::on_pbChangePath_clicked()
{
    QString s;
    s = QFileDialog::getOpenFileName(this,"Choose Athan File",QDir::homePath(),"Audio (*.*)");
    if (!s.isNull()) m_ui->tbAthanPath->setText(s);
}

void settingsDialog::on_pbTestAthan_clicked()
{
    if(munadi->isAthanPlaying())
        munadi->stopAthan();
    else
    {
        QString temp = munadi->settings->athanPath;
        munadi->settings->athanPath = m_ui->tbAthanPath->text();
        munadi->playAthan();
        munadi->settings->athanPath = temp;
    }

}

void settingsDialog::on_bbAthanOptions_accepted()
{
    syncSettings();
}

void settingsDialog::on_bbCalcMethods_accepted()
{
    syncSettings();
}

void settingsDialog::on_bbLocation_accepted()
{
    syncSettings();
}

void settingsDialog::syncSettings()
{
    // Under any settings tab, this should be upated and called
    munadi->settings->setCity(m_ui->tbLocationAddress->text(),
                              m_ui->tbLatitude->text().toDouble(),
                              m_ui->tbLongitude->text().toDouble(),
                              m_ui->sbGmtOffset->value(),
                              m_ui->cbDaylightSaving->isChecked(),
                              m_ui->cbMathhab->currentIndex() + 1,
                              m_ui->cbMethod->currentIndex() + 1);

    // Method tab
    // ... not need, setCity does it all

    // Location tab
    // ... not need, setCity does it all

    // Athan tab
    munadi->settings->athanPath = m_ui->tbAthanPath->text();

    munadi->settings->farjEnabled = m_ui->cbFajrEnabled->isChecked();
    munadi->settings->duhrEnabled = m_ui->cbDuhrEnabled->isChecked();
    munadi->settings->asrEnabled = m_ui->cbAsrEnabled->isChecked();
    munadi->settings->magribEnabled = m_ui->cbMagribEnabled->isChecked();
    munadi->settings->ishaEnabled = m_ui->cbIshaEnabled->isChecked();

    munadi->settings->farjAdjustment = m_ui->sbFajrAdjustment->value();
    munadi->settings->duhrAdjustment = m_ui->sbDuhrAdjustment->value();
    munadi->settings->asrAdjustment = m_ui->sbAsrAdjustment->value();
    munadi->settings->magribAdjustment = m_ui->sbMagribAdjustment->value();
    munadi->settings->ishaAdjustment = m_ui->sbIshaAdjustment->value();

    // Refresh
    munadi->calculatePrayer();
    munadi->calculateAngle();

    close();
}

void settingsDialog::on_bbLocation_rejected()
{
    close();
}

void settingsDialog::on_bbCalcMethods_rejected()
{
    close();
}

void settingsDialog::on_bbAthanOptions_rejected()
{
    close();
}
