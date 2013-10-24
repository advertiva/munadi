#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtCore>
#include <QDesktopWidget>
#include "munadiengine.h"
#include "settingsdialog.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.indt.munadi")

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MunadiEngine * munadi;
    settingsDialog * addCity;
    QTimer * timer;
    bool closeWindow;
    void loadSettings();
    void saveSettings();
    bool eventFilter(QObject *, QEvent *);
protected:
    void closeEvent(QCloseEvent *);

private slots:
    void on_actionNew_City_triggered();
    void updateDisplay();
    void on_actionE_xit_triggered();
    void on_actionAbout_Munadi_triggered();
    void on_actionPlay_Stop_Athan_triggered();
    void on_actionTEST_PRAYER_triggered();
    void on_actionShow_On_Athan_triggered();
    void orientationChanged();

public slots:
    Q_SCRIPTABLE int top_application();
};

#endif // MAINWINDOW_H
