#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "settings.h"
#include <QtWidgets/QFileDialog>

settingsDialog::settingsDialog(MunadiEngine * munadiEngine, QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::settingsDialog)
{
    m_ui->setupUi(this);

    //this->setGeometry(0, 0, 1024, 600);

    munadi = munadiEngine;
    populateCountires();
    setGeometry(munadi->settings->settingScreenGeo);

    connect(m_ui->pbFajrUp, SIGNAL(clicked()), m_ui->sbFajrAdjustment, SLOT(stepUp()));
    connect(m_ui->pbFajrDown, SIGNAL(clicked()), m_ui->sbFajrAdjustment, SLOT(stepDown()));

    connect(m_ui->pbDuhrUp, SIGNAL(clicked()), m_ui->sbDuhrAdjustment, SLOT(stepUp()));
    connect(m_ui->pbDuhrDown, SIGNAL(clicked()), m_ui->sbDuhrAdjustment, SLOT(stepDown()));

    connect(m_ui->pbAsrUp, SIGNAL(clicked()), m_ui->sbAsrAdjustment, SLOT(stepUp()));
    connect(m_ui->pbAsrDown, SIGNAL(clicked()), m_ui->sbAsrAdjustment, SLOT(stepDown()));

    connect(m_ui->pbMagribUp, SIGNAL(clicked()), m_ui->sbMagribAdjustment, SLOT(stepUp()));
    connect(m_ui->pbMagribDown, SIGNAL(clicked()), m_ui->sbMagribAdjustment, SLOT(stepDown()));

    connect(m_ui->pbIshaUp, SIGNAL(clicked()), m_ui->sbIshaAdjustment, SLOT(stepUp()));
    connect(m_ui->pbIshaDown, SIGNAL(clicked()), m_ui->sbIshaAdjustment, SLOT(stepDown()));

    connect(this, SIGNAL(destroyed()), this, SLOT(on_settingsDialog_destroyed()));

    // Method tab
    m_ui->cbMathhab->setCurrentIndex(munadi->settings->currentCity.method.mathhab-1);          // show existing
    m_ui->cbMethod->setCurrentIndex(munadi->settings->currentCity.calcMethod-1);               // settings to the user

    // Location tab
    m_ui->cbDaylightSaving->setChecked(munadi->settings->currentCity.location.dst);
    m_ui->tbLatitude->setText(QString::number(munadi->settings->currentCity.location.degreeLat));
    m_ui->tbLongitude->setText(QString::number(munadi->settings->currentCity.location.degreeLong));
    m_ui->tbGmtOffset->setText(QString::number(munadi->settings->currentCity.location.gmtDiff));
    m_ui->tbLocation->setText(munadi->settings->currentCity.name);

    // Athan tab
    //m_ui->tbAthanPath->setText(munadi->settings->athanPath);
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

void settingsDialog::closeEvent(QCloseEvent * e)
{
    munadi->settings->settingScreenGeo = this->geometry();
    e->accept();
}

//void settingsDialog::on_btnProbeWS_clicked()
//{
    //QString query = WEBSERVICE_URL + m_ui->tbLocationAddress->text();
    //netManager->get(QNetworkRequest(QUrl(query)));
//}
//void settingsDialog::netReplyReceived(QNetworkReply * reply)
//{
//    QByteArray data(reply->readAll());
//    if(data.size() == 0 || !isdigit(data[0]))
//    {
//        QMessageBox::information(this, "Location not found", "The address appears to be invalid or not found.\n"
//                                 "Please enter details manually.");
//        return;
//    }
//    foundCity = parseIPLocTools(data);
//    displayResults(foundCity);
//}
//City settingsDialog::parseIPLocTools(QByteArray & data)
//{
//    QList<QByteArray> results = data.split(',');
//    City city;

//    city.name = m_ui->tbLocationAddress->text();
//    city.location.degreeLat = results[0].toDouble();
//    city.location.degreeLong = results[1].toDouble();

//    return city;
//}
void settingsDialog::displayResults(City & city)
{
    m_ui->tbLatitude->setText(QString::number(city.location.degreeLat));
    m_ui->tbLongitude->setText(QString::number(city.location.degreeLong));
}

//void settingsDialog::on_pbChangePath_clicked()
//{
//    QString s;
//    s = QFileDialog::getOpenFileName(this,"Choose Athan File",QDir::homePath(),"Audio (*.*)");
//    if (!s.isNull()) m_ui->tbAthanPath->setText(s);
//}

//void settingsDialog::on_pbTestAthan_clicked()
//{
//    if(munadi->isAthanPlaying())
//        munadi->stopAthan();
//    else
//    {
//        QString temp = munadi->settings->athanPath;
//        munadi->settings->athanPath = m_ui->tbAthanPath->text();
//        munadi->playAthan();
//        munadi->settings->athanPath = temp;
//    }

//}


void settingsDialog::syncSettings()
{
    // Under any settings tab, this should be upated and called
    munadi->settings->setCity(m_ui->tbLocation->text(),
                              m_ui->tbLatitude->text().toDouble(),
                              m_ui->tbLongitude->text().toDouble(),
                              m_ui->tbGmtOffset->text().toInt(),
                              m_ui->cbDaylightSaving->isChecked(),
                              m_ui->cbMathhab->currentIndex() + 1,
                              m_ui->cbMethod->currentIndex() + 1);

    // Method tab
    // ... not need, setCity does it all

    // Location tab
    // ... not need, setCity does it all

    // Athan tab
    //munadi->settings->athanPath = m_ui->tbAthanPath->text();

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
}

void settingsDialog::on_cancelButton_clicked()
{
    // Refresh
    //munadi->calculatePrayer();
    //munadi->calculateAngle();

    dout << "Caling close .............";

    this->close();

    dout << "Called close .............";
}

void settingsDialog::on_saveButton_clicked()
{
    this->syncSettings();
    this->close();
}

void settingsDialog::populateCountires()
{
    QFile f(":/data/countries.tsv");

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
             qDebug() << "Failed to open file!";
             return;
    }

    QTextStream ts(&f);

    while(!ts.atEnd())
    {
        QStringList str;
        str = ts.readLine().split('\t');

        m_ui->cbCountries->addItem(str[0], str[1]);
    }

    m_ui->cbCountries->setCurrentIndex(-1);

    f.close();
}

void settingsDialog::on_cbCountries_currentIndexChanged(int index)
{
    if(index == -1)
    {
        m_ui->cbCities->setCurrentIndex(-1);
        return;
    }

    m_ui->cbCities->clear();
    m_ui->cbCities->setInsertPolicy(QComboBox::InsertAlphabetically);

    QString cc = m_ui->cbCountries->itemData(index).toString();

    QFile f(":/data/cities.tsv");

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
             qDebug() << "Failed to open file!";
             return;
    }

    QTextStream ts(&f);

    while(!ts.atEnd())
    {
        QString input = ts.readLine();

        if(input.startsWith(cc))
        {
            QStringList str = input.split('\t');

            m_ui->cbCities->addItem(str[1], input);
        }
    }

    f.close();
}

void settingsDialog::on_cbCities_currentIndexChanged(int index)
{
    if(index == -1) return;

    QStringList cityData = m_ui->cbCities->itemData(index).toString().split('\t');

    m_ui->tbLocation->setText(cityData[1] + ", " + m_ui->cbCountries->currentText());
    m_ui->tbLatitude->setText(cityData[2]);
    m_ui->tbLongitude->setText(cityData[3]);
    m_ui->tbGmtOffset->setText(cityData[4]);
}
