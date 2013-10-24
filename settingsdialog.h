#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QtWidgets/QDialog>
#include "munadiengine.h"
#include "globals.h"

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
    void closeEvent(QCloseEvent *e);

private:
    Ui::settingsDialog *m_ui;
    MunadiEngine * munadi;
    QString locationInput;
    City foundCity;

    void autoDetectLocation();
    void displayResults(City & city);
    void populateCountires();
    void syncSettings();

private slots:
    void on_cancelButton_clicked();
    void on_saveButton_clicked();
    void on_cbCountries_currentIndexChanged(int index);
    void on_cbCities_currentIndexChanged(int index);
};

#endif // SETTINGSDIALOG_H
