#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QtCore>
#include <QTimer>
//#ifdef Q_WS_MAEMO_5
//    #include <QDesktopWidget>
//#endif
#include "munadiengine.h"
#include "settingsdialog.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
//    Q_CLASSINFO("D-Bus Interface", "org.indt.munadi")

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
//#ifndef Q_WS_MAEMO_5
//    QSystemTrayIcon * tray;
//    QMenu * trayMenu;
//    void createTrayMenu();
//#endif
protected:
    void closeEvent(QCloseEvent *);
    void hideEvent(QHideEvent *);
    void showEvent(QShowEvent *);

private slots:
    void on_actionNew_City_triggered();
    void updateDisplay();
    void toggleView(){ isVisible() ? hide() : show(); }
    void on_actionE_xit_triggered();
    void on_actionAbout_Munadi_triggered();
    void on_actionPlay_Stop_Athan_triggered();
#ifdef TESTING
    void on_actionTEST_PRAYER_triggered();
#endif
    void on_actionShow_On_Athan_triggered();
//#ifdef Q_WS_MAEMO_5
//    void iconActivated(QSystemTrayIcon::ActivationReason reason);
//    void orientationChanged();
//#endif

//public slots:
//    Q_SCRIPTABLE int top_application();
    void on_pbSettings_clicked();
    void on_pbPlay_clicked();
    void on_pbStop_clicked();
};

#endif // MAINWINDOW_H
